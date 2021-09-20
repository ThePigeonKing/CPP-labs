#include <iomanip>      // <-- for std::setprecision

#include "struct.h"

using tpk2::Ellipse;

int main(int argc, char const *argv[]) {
  int a = 0, b = 0;

  std::cout << "---> Ellipse " << GREEN << " x^2/a^2 + y^2/b^2 = 1  " << RESET
            << "<---" << std::endl;

  std::cout << "Enter a: ";
  std::cin >> a;
  if (!std::cin.good()) {
    return -1;
  }

  std::cout << "Enter b: ";
  std::cin >> b;
  if (!std::cin.good()) {
    return -1;
  }

// init with values
  Ellipse elps(a, b);

  std::cout << std::setprecision(4) << std::endl
            << "Focal length of ellipse: " << elps.focal_distance() << std::endl;

  return 0;
}
