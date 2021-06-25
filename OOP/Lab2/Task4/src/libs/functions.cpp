#include "functions.hpp"

// print program info
void PrintProgramInfo() {
  std::wcout << std::endl
             << L"Программа выводит в стандартный поток вывода элементы двух "
                L"множеств целых чисел и результат их пересечения. Первое "
                L"множество – множество чисел от 1 до N, делящихся без остатка "
                L"на сумму своих цифр. Второе множество – множество целых "
                L"чисел то 1 до N, сумма цифр которых является четной. "
                L"Параметр N передается пользователем в виде аргумента "
                L"командной строки."
             << std::endl
             << std::endl;
  std::wcout << L"Пример запуска: task4 <N>" << std::endl << std::endl;
}

void PrintExitInfo(int exitCode) {
  switch (exitCode) {
  case 0:
    break;
  case 1:
    std::wcout << L"Error code " << exitCode
               << L": N value must be integer over 2." << std::endl;
    break;
  default:
    std::wcout << L"Error code " << exitCode << L": undefined error."
               << std::endl;
  }
}

int GetN(const std::wstring &nString) {
  bool isError;
  int N = Mts::StrToInt(nString, 10, isError);
  if (!isError && N > 1) {
    return N;
  }
  return -1;
}

// множество чисел от 1 до N, делящихся без остатка на сумму своих цифр
std::set<int> MakeFirstSet(int N) {
  std::set<int> firstSet;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    int number = i;
    while (number > 0) {
      sum += number % 10;
      number /= 10;
    }
    if (i % sum == 0) {
      firstSet.insert(i);
    }
  }
  return firstSet;
}

// множество целых чисел то 1 до N, сумма цифр которых является четной
std::set<int> MakeSecondSet(int N) {
  std::set<int> secondSet;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    int number = i;
    while (number > 0) {
      sum += number % 10;
      number /= 10;
    }
    if (sum % 2 == 0) {
      secondSet.insert(i);
    }
  }
  return secondSet;
}

std::set<int> CrossSet(std::set<int> const &set1, std::set<int> const &set2) {
  std::set<int> crossSet;
  std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                        std::inserter(crossSet, crossSet.begin()));
  return crossSet;
}

void PrintSet(const std::set<int> &set) {
  for (auto it = set.begin(); it != set.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
