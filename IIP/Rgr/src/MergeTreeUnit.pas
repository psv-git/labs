UNIT MergeTreeUnit;

INTERFACE

USES
  SupportUnit;

PROCEDURE MergeTree(VAR FRcd: FileOfRecords; VAR Root: Ptr);

IMPLEMENTATION

PROCEDURE PrepareTempFile(VAR FRcd, FTmp: FileOfRecords);
VAR
  TmpRec: RecordProt;
BEGIN
  ASSIGN(FTmp, 'TMP');
  RESET(FRcd);
  REWRITE(FTmp);
  WHILE NOT EOF(FRcd)
  DO
    BEGIN
      READ(FRcd, TmpRec);
      WRITE(FTmp, TmpRec);
    END;
  RESET(FTmp);
  REWRITE(FRcd);
END;

PROCEDURE PrepareArguments(VAR MNode, FNode: Ptr; VAR State: OrderState);
VAR
  TmpRec: RecordProt;
BEGIN
  TmpRec := FNode^.Rec;
  FNode^.Rec := MNode^.Rec;
  MNode^.Rec := TmpRec;
  State := Null;
END;

PROCEDURE OrderTree(VAR FRcd: FileOfRecords; VAR Root, MNode, FNode: Ptr; VAR State: OrderState);
BEGIN
  IF FNode^.Rec.Str = MNode^.Rec.Str
  THEN
    BEGIN
      MNode^.Rec.Count := MNode^.Rec.Count + FNode^.Rec.Count;
      State := Null;
    END
  ELSE
    CASE FNode^.Rec.Str < MNode^.Rec.Str OF
      TRUE:
        IF MNode^.Left <> NIL
        THEN
          OrderTree(FRcd, Root, MNode^.Left, FNode, State)
        ELSE
          IF State = Null
          THEN
            WRITE(FRcd, FNode^.Rec);
      FALSE:
        IF MNode^.Right <> NIL
        THEN
          BEGIN
            State := Swap;
            OrderTree(FRcd, Root, MNode^.Right, FNode, State);
            IF State = Swap
            THEN
              BEGIN
                PrepareArguments(MNode, FNode, State);
                OrderTree(FRcd, Root, Root, FNode, State);
              END;
          END
        ELSE
          BEGIN
            PrepareArguments(MNode, FNode, State);
            OrderTree(FRcd, Root, Root, FNode, State);
          END;
    END;
END;

PROCEDURE WriteTree(VAR FRcd: FileOfRecords; VAR MNode: Ptr);
BEGIN
  IF MNode^.Left <> NIL
  THEN
    WriteTree(FRcd, MNode^.Left);
  WRITE(FRcd, MNode^.Rec);
  IF MNode^.Right <> NIL
  THEN
    WriteTree(FRcd, MNode^.Right);
  DISPOSE(MNode);
END;

PROCEDURE MergeTree(VAR FRcd: FileOfRecords; VAR Root: Ptr);
VAR
  FNode: Ptr;
  FTmp: FileOfRecords;
  State: OrderState;
BEGIN
  CreateNode(FNode);
  PrepareTempFile(FRcd, FTmp);
  WHILE NOT EOF(FTmp)
  DO
    BEGIN
      State := Null;
      READ(FTmp, FNode^.Rec);
      OrderTree(FRcd, Root, Root, FNode, State);
    END;
  WriteTree(FRcd, Root);
  DISPOSE(FNode);
  CLOSE(FTmp);
  ERASE(FTmp);
END;

BEGIN
END.

