#include "../libs/functions.hpp"
#include "stdafx.h"

int main(int argc, char *argv[]) {
  Mts::SetLocale("ru");

  // check args
  if (argc != 2) {
    PrintProgramInfo();
    return 0;
  }

  int nInt = GetN(Mts::CharToWide(argv[1]));
  if (nInt < 0) {
    PrintExitInfo(1);
    return 1;
  }

  std::set<int> firstSet = MakeFirstSet(nInt);
  std::set<int> secondSet = MakeSecondSet(nInt);
  std::set<int> crossSet = CrossSet(firstSet, secondSet);

  PrintSet(firstSet);
  PrintSet(secondSet);
  PrintSet(crossSet);

  return 0;
}
