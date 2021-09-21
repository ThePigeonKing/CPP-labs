#include "struct.h"

tpk2::Ellipse::~Ellipse() {
  std::cout << YELLOW << "Ellipse with a = " << a << " and b = " << b
            << " destroyed!" << RESET << std::endl;
}

tpk2::Ellipse::Ellipse(int num1, int num2) {
  if (num1 == 0) {
    std::cout << GREEN << "[!Warn] A was reset to 1 by default" << RESET
              << std::endl;
    num1 = 1;
  }
  if (num1 == 0) {
    std::cout << GREEN << "[!Warn] B was reset to 1 by default" << RESET
              << std::endl;
    num2 = 1;
  }

  set_a(num1);
  set_b(num2);

  // std::cout << "Created ellipse!" << std::endl;
}

[[nodiscard]] double tpk2::Ellipse::focal_distance() {
  return (2 * (sqrt(abs(pow(a, 2) - pow(b, 2)))));
}

[[nodiscard]] double tpk2::Ellipse::eccentricity() {
  if (a <= b) {
    return sqrt(1 - (pow(a, 2) / pow(b, 2)));
  } else {
    return sqrt(1 - (pow(b, 2) / pow(a, 2)));
  }
}

[[nodiscard]] double tpk2::Ellipse::length() { return (M_PI * (a + b)); }

[[nodiscard]] double tpk2::Ellipse::area() { return (M_PI * a * b); }


[[nodiscard]] double tpk2::Ellipse::min_dist(double focal){
  if (a >= b){
    return (a - focal);
  } else {
    return (b - focal);
  }
}

[[nodiscard]] double tpk2::Ellipse::max_dist(double focal){
  if (a >= b){
    return (a + focal);
  } else {
    return (b + focal);
  }
}

// 
[[nodiscard]] double* tpk2::Ellipse::find_ys(double x){
  
  
}