UNIT SupportUnit;

INTERFACE

CONST
  TreeSize = 5;                              { размер списка }
  MaxStrLen = 50;                            { длина строки дл€ слова }
TYPE
  ParseState = (SkipChar, Letter, Forward, NextWord, Hyphen);
  OrderState = (Null, Swap);
  Ptr = ^NodeProt;
  RecordProt =  RECORD                        { прототип записи дл€ файлов }
                  Str: STRING[MaxStrLen];     { строка под слово }
                  Count: CARDINAL;            { количество экземпл€ров данного слова в тексте }
                END;
  NodeProt =  RECORD                          { прототип ноды дл€ пам€ти }
                Rec: RecordProt;
                Left: Ptr;
                Right: Ptr;
              END;
  FileOfRecords = FILE OF RecordProt;

PROCEDURE CreateNode(VAR MNode: Ptr);

IMPLEMENTATION

{ создать запись }
PROCEDURE CreateNode(VAR MNode: Ptr);
BEGIN
  NEW(MNode);
  MNode^.Rec.Str := '';
  MNode^.Rec.Count := 1;
  MNode^.Left := NIL;
  MNode^.Right := NIL;
END;

BEGIN
END.
