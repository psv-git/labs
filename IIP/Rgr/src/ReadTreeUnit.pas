UNIT ReadTreeUnit;

INTERFACE

USES
  SupportUnit;

FUNCTION ReadTree(VAR FTxt: TEXT): Ptr;

IMPLEMENTATION

FUNCTION LowCase(VAR Ch: CHAR): CHAR;
BEGIN
  IF Ch IN ['А' .. 'Я']
  THEN
    CASE Ch OF
      'А': Ch := 'а'; 'Б': Ch := 'б'; 'В': Ch := 'в'; 'Г': Ch := 'г'; 'Д': Ch := 'д'; 'Е': Ch := 'е';
      'Ё': Ch := 'ё'; 'Ж': Ch := 'ж'; 'З': Ch := 'з'; 'И': Ch := 'и'; 'Й': Ch := 'й'; 'К': Ch := 'к';
      'Л': Ch := 'л'; 'М': Ch := 'м'; 'Н': Ch := 'н'; 'О': Ch := 'о'; 'П': Ch := 'п'; 'Р': Ch := 'р';
      'С': Ch := 'с'; 'Т': Ch := 'т'; 'У': Ch := 'у'; 'Ф': Ch := 'ф'; 'Х': Ch := 'х'; 'Ц': Ch := 'ц';
      'Ч': Ch := 'ч'; 'Ш': Ch := 'ш'; 'Щ': Ch := 'щ'; 'Ы': Ch := 'ы'; 'Э': Ch := 'э'; 'Ю': Ch := 'ю';
      'Я': Ch := 'я'; 'Ь': Ch := 'ь'; 'Ъ': Ch := 'ъ';
    END;
  IF Ch IN ['A' .. 'Z']
  THEN
    CASE Ch OF
      'A': Ch := 'a'; 'B': Ch := 'b'; 'C': Ch := 'c'; 'D': Ch := 'd'; 'E': Ch := 'e'; 'F': Ch := 'f';
      'G': Ch := 'g'; 'H': Ch := 'h'; 'I': Ch := 'i'; 'J': Ch := 'j'; 'K': Ch := 'k'; 'L': Ch := 'l';
      'M': Ch := 'm'; 'N': Ch := 'n'; 'O': Ch := 'o'; 'P': Ch := 'p'; 'Q': Ch := 'q'; 'R': Ch := 'r';
      'S': Ch := 's'; 'T': Ch := 't'; 'U': Ch := 'u'; 'V': Ch := 'v'; 'W': Ch := 'w'; 'X': Ch := 'x';
      'Y': Ch := 'y'; 'Z': Ch := 'z';
    END;
  LowCase := Ch;
END;

{ проверка на букву для CheckParseState }
FUNCTION IsLetter(VAR Ch: CHAR): BOOLEAN;
BEGIN
  CASE (Ch IN ['a' .. 'z']) OR (Ch IN ['A' .. 'Z']) OR (Ch IN ['а' .. 'я']) OR (Ch IN ['А' .. 'Я']) OF
    TRUE: IsLetter := TRUE;
    FALSE: IsLetter := FALSE;
  END;
END;

{ проверка статуса для ReadWord }
PROCEDURE CheckParseState(VAR Ch: CHAR; VAR State: ParseState);
BEGIN
  IF ((State = SkipChar) OR (State = NextWord) OR (State = Hyphen)) AND IsLetter(Ch) THEN State := Letter ELSE
  IF (State = Letter) AND (Ch = '-') THEN State := Forward ELSE
  IF (State = Forward) AND IsLetter(Ch) THEN State := Hyphen ELSE
  IF ((State = Letter) OR (State = Forward) OR (State = Hyphen)) AND NOT IsLetter(Ch) THEN State := NextWord ELSE
  IF (State = NextWord) AND NOT IsLetter(Ch) THEN State := SkipChar;
END;

{ прочитать слово в запись из файла; слова, превышающие допустимую длину, отбрасываются }
FUNCTION ReadWord(VAR FTxt: TEXT): Ptr;
VAR
  Ch: CHAR;
  MNode: Ptr;
  TmpStr: STRING;
  State: ParseState;
  ReadCount: CARDINAL;
BEGIN
  MNode := NIL;
  State := SkipChar;
  TmpStr := '';
  ReadCount := 0;                                            { контролируем количество считаных символов }
  WHILE NOT EOF(FTxt) AND (State <> NextWord)
  DO
    BEGIN
      READ(FTxt, Ch);
      CheckParseState(Ch, State);                            { устанавливаем статус парсера }
      IF State = Letter                                      { проверяем статус и текущую длину строки }
      THEN
        BEGIN
          ReadCount := ReadCount + 1;
          IF Length(TmpStr) < MaxStrLen
          THEN
            TmpStr := TmpStr + LowCase(Ch)                   { добавляем в строку букву }
        END
      ELSE
        IF State = Hyphen                                    { проверяем статус и текущую длину строки }
        THEN
          BEGIN
            ReadCount := ReadCount + 2;
            IF Length(TmpStr) < MaxStrLen
            THEN
              TmpStr := TmpStr + '-' + LowCase(Ch);          { добавляем в строку дефис и букву }
          END;
    END;
  IF (State = NextWord) AND (ReadCount <= MaxStrLen)         { конец слова и кол-во считаных символов не превышает длину строки }
  THEN
    BEGIN
      CreateNode(MNode);                                     { создаем запись }
      MNode^.Rec.Str := TmpStr;                              { добавляем в запись слово }
    END;
  ReadWord := MNode;
END;

{ расположить запись в дереве }
FUNCTION AttachNode(VAR Root, MNode: Ptr): BOOLEAN;
VAR
  Result: BOOLEAN;
BEGIN
  Result := FALSE;
  IF Root^.Rec.Str = MNode^.Rec.Str        { для одинаковых слов увеличиваем счетчик слова в текущем элементе }
  THEN
    BEGIN
      Root^.Rec.Count := Root^.Rec.Count + 1;
      DISPOSE(MNode);
    END
  ELSE
    IF Root^.Rec.Str > MNode^.Rec.Str      { если строка в текущем Root больше.. }
    THEN
      IF Root^.Left <> NIL                 { ..и левее есть элемент, спускаемся к нему }
      THEN
        Result := AttachNode(Root^.Left, MNode)
      ELSE
        BEGIN
          Root^.Left := MNode;             { если левее элементов нет то кладем элемент влево }
          AttachNode := TRUE;
        END
    ELSE
      IF Root^.Right <> NIL                { если строка в текущем Root меньше и правее есть элемент, спускаемся к нему }
      THEN
        Result := AttachNode(Root^.Right, MNode)
      ELSE
        BEGIN
          Root^.Right := MNode;            { если правее элементов нет то кладем элемент вправо }
          AttachNode := TRUE;
        END;
  AttachNode := Result;
END;

{ прочитать слова из файла и отсортировать деревом }
FUNCTION ReadTree(VAR FTxt: TEXT): Ptr;
VAR
  Root, MNode: Ptr;
  NodeCount: CARDINAL;
BEGIN
  Root := ReadWord(FTxt);                              { читаем корень }
  IF Root <> NIL
  THEN
    BEGIN
      NodeCount := 1;
      WHILE NOT EOF(FTxt) AND (NodeCount < TreeSize)
      DO
        BEGIN
          MNode := ReadWord(FTxt);                     { читаем ноду }
          IF MNode <> NIL                              { если нода была прочитана }
          THEN
            IF AttachNode(Root, MNode)        { добавляем ноду в дерево }
            THEN
              NodeCount := NodeCount + 1;
        END;
    END;
  ReadTree := Root;
END;

BEGIN
END.

