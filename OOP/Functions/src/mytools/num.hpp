#ifndef NUM_HPP
#define NUM_HPP


#include <limits>
#include <string>


namespace Mts {

  // INFINITY CONSTANTS =======================================================
  constexpr double DINF = std::numeric_limits<double>::infinity();

  // MIN/MAX CONSTANTS ========================================================
  const int INT_MIN = std::numeric_limits<int>::lowest();
  const int INT_MAX = std::numeric_limits<int>::max();
  constexpr double DOUBLE_MIN = std::numeric_limits<double>::lowest();
  constexpr double DOUBLE_MAX = std::numeric_limits<double>::max();

  // BITE SIZE CONSTANTS ======================================================
  const int INT_BIT_SIZE = sizeof(int) * 8;
  const int DOUBLE_BIT_SIZE = sizeof(double) * 8;

  // GET NUMBER SIGN ==========================================================
  int GetSign(int number);
  int GetSign(double number);

  // GET ABSOLUTE =============================================================
  int Abs(int number);
  double Abs(double number);

  // INTEGER CALCULATION ======================================================
  int Add(int operand1, int operand2, bool &error);
  int Sub(int operand1, int operand2, bool &error);
  int Mul(int operand1, int operand2, bool &error);
  int Div(int operand1, int operand2, bool &error);


  // DOUBLE CALCULATION =======================================================
  double Add(double operand1, double operand2, bool &error);
  double Sub(double operand1, double operand2, bool &error);
  double Mul(double operand1, double operand2, bool &error);
  double Div(double operand1, double operand2, bool &error);


  // FROM NUMBER TO STRING ====================================================
  std::wstring IntToStr(int number, int radix, bool &error);
  std::wstring IntToStr(int number);
  std::wstring DoubleToStr(double number);

}


#endif // NUM_HPP
