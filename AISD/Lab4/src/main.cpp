#include "func.cpp"


int main(int argc, char *argv[]) {
  if (argc == 2) {
    int N = atoi(argv[1]);
    if (N % 2 != 0) cout << "Bad argument" << endl;
    else Foo(N);
  }

  return 0;
}
