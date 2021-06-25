UNIT MainUnit;

INTERFACE

PROCEDURE MakeDB(VAR FTxt: TEXT);
PROCEDURE PrintDB(VAR FTxt: TEXT);

IMPLEMENTATION

USES
  SupportUnit, ReadTreeUnit, MergeTreeUnit;

PROCEDURE MakeDB(VAR FTxt: TEXT);
VAR
  FRcd: FileOfRecords;
  Root: Ptr;
BEGIN
  ASSIGN(FRcd, 'DATA.BD');
  REWRITE(FRcd);
  RESET(FTxt);
  IF NOT EOF(FTxt)
  THEN
    WHILE NOT EOF(FTxt)
    DO
      BEGIN
        Root := ReadTree(FTxt);
        IF Root <> NIL
        THEN
          MergeTree(FRcd, Root);
      END
  ELSE
    WRITELN(OUTPUT, 'Error: input file is empty.');
  CLOSE(FRcd);
  CLOSE(FTxt);
END;

PROCEDURE PrintDB(VAR FTxt: TEXT);
VAR
  TmpRec: RecordProt;
  FRcd: FileOfRecords;
BEGIN
  ASSIGN(FRcd, 'DATA.BD');
  RESET(FRcd);
  IF NOT EOF(FRcd)
  THEN
    BEGIN
      ASSIGN(FTxt, 'OUTPUT.TXT');
      REWRITE(FTxt);
      WHILE NOT EOF(FRcd)
      DO
        BEGIN
          READ(FRcd, TmpRec);
          WRITELN(FTxt, TmpRec.Str, ' ', TmpRec.Count);
        END;
      CLOSE(FTxt);
      CLOSE(FRcd);
    END
  ELSE
    WRITELN(OUTPUT, 'Error: database file is empty.');
END;

BEGIN
END.
