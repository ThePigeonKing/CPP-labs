#include <iomanip>  // <-- for std::setprecision

#include "struct.h"

using tpk2::Ellipse;

int main(int argc, char const* argv[]) {
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

  double focal = elps.focal_distance(), x_find, result;

  std::cout << std::setprecision(4) << std::endl
            << "Focal length of ellipse: " << focal << std::endl
            << "Eccentricity: " << elps.eccentricity() << std::endl
            << "Lenght of ellipse: " << elps.length() << std::endl
            << "Area of ellipse: " << elps.area() << std::endl
            << "Minimum distance from focus: " << elps.min_dist(focal)
            << std::endl
            << "Maximum distance from focus: " << elps.max_dist(focal)
            << std::endl;

  std::cout << "Enter x for which to find y: ";
  std::cin >> x_find;
  if (!std::cin.good()) {
    return -1;
  }

  try {
    result = elps.find_ys(x_find);

    std::cout << "y(" << x_find << ") = ";

    if (abs(x_find) != abs(a)) {
      std::cout << "±";
    }

    std::cout << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << GREEN << "[!Error] " << e.what() << std::endl;
  }

  return 0;
}
