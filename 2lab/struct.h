#ifndef LAB2_STR
#define LAB2_STR

#include <cmath>
#include <iostream>
#include <string>

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

namespace tpk2 {

//! x^2 / a^2 + y^2 / b^2 = 1
class Ellipse {
 private:
  int a = 1;
  int b = 1;

 public:
  [[nodiscard]] int get_a() { return a; }
  [[nodiscard]] int get_b() { return b; }

  void set_a(int number) {
    if (number != 0) {
      a = number;
    } else {
      std::cout << "Fail in setting a!" << std::endl;
      return;
    }
  }

  void set_b(int number) {
    if (number != 0) {
      b = number;
    } else {
      std::cout << "Fail in setting b!" << std::endl;
      return;
    }
  }

  [[nodiscard]] double focal_distance();

  [[nodiscard]] double eccentricity();

  [[nodiscard]] double length();

  [[nodiscard]] double area();

  Ellipse(int num1 = 1, int num2 = 1);
  ~Ellipse();
};

}  // namespace tpk2

#endif