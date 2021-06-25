#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;


class Array {

  public:

    Array() {}
    Array(int N, char *m);
    ~Array() {}

    char* mas;
    int len, hSize, qSize;
    int openCount;
    long int elemCount;

    void recOrdering(int pos, ostream &out);
    bool addBrakeToPos(char ch, int pos);
    bool checkOrder(int pos);
    void printArray(ostream &out);

};


Array::Array(int N, char *m) {
  len = N;
  hSize = N / 2;
  qSize = hSize / 2;
  openCount = 0;
  elemCount = 0;
  mas = m;
}


void Array::printArray(ostream &out) {
  for (int i = 0; i < len; i++) out << mas[i];
  out << endl;
  elemCount++;
}


bool Array::addBrakeToPos(char ch, int pos) {
  if (ch == ')') {
    if (mas[pos - 1] == '[') return false;
  } else {
    if (ch == ']') {
      if (mas[pos - 1] == '(') return false;
    } else {
      if (pos >= hSize) {
        openCount++;
        if (openCount > qSize) return false;
      }
    }
  }
  mas[pos] = ch;
  if (!checkOrder(pos)) return false;
  return true;
}


bool Array::checkOrder(int pos) {
  char stk[pos];
  int count = -1;
  for (int i = 0; i < pos; i++) {
    if (mas[i] == '(') {
      count++;
      stk[count] = '(';
    } else {
      if (mas[i] == '[') {
        count++;
        stk[count] = '[';
      } else {
        if (count >= 0) {
          if (mas[i] == ')') {
            if (stk[count] == '(') count--;
            else return false;
          } else {
            if (stk[count] == '[') count--;
            else return false;
          }
        } else return false;
      }
    }
  }
  if (pos == len) return count < 0;
  else return true;
}


void Array::recOrdering(int pos, ostream &out) {
  if (pos != len) {
    int opCount = openCount;
    if (pos < len - 1) {
      if (addBrakeToPos('(', pos)) recOrdering(pos+1, out);
      openCount = opCount;
      if (addBrakeToPos('[', pos)) recOrdering(pos+1, out);
      openCount = opCount;
    }
    if (pos > 0) {
      if (addBrakeToPos(')', pos)) recOrdering(pos+1, out);
      openCount = opCount;
      if (addBrakeToPos(']', pos)) recOrdering(pos+1, out);
      openCount = opCount;
    }
  } else {
    if (checkOrder(pos)) printArray(out);
  }
}


// ============================================================================

// произведение чисел от beg до end
unsigned long long int Factorial(int beg, int end) {
  if (beg < end) return beg * Factorial(beg + 1, end);
  else return end;
}


// получить количество элементов
unsigned long long int GetElementCount(int pairCount) {
  unsigned long long int C = Factorial(pairCount + 1, 2 * pairCount) / Factorial(1, pairCount);
  return ((C * pow(2, pairCount)) / (pairCount + 1));
}


// 
void Foo(int N) {
  clock_t t = clock();
  ofstream outFile("out.txt", ios::out);
  unsigned long long int expElementCount = GetElementCount(N / 2);

  char mas[N];
  Array arr(N, mas);
  arr.recOrdering(0, cout);

  cout << endl << "N = " << N;
  cout << "    Expected elements count: " << expElementCount;
  cout << "    Current elements count: " << arr.elemCount;
  cout << "    Run time = " << (float)(clock() - t) / CLOCKS_PER_SEC << endl;
}
