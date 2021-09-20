#include "struct.h"

tpk2::Ellipse::~Ellipse() {
  std::cout << YELLOW << "Ellipse with a = " << a << " and b = " << b
            << " destroyed!" << RESET << std::endl;
}

tpk2::Ellipse::Ellipse(int num1 = 1, int num2 = 1) { 

    if (num1 == 0){
        std::cout << GREEN << "[!Warn] A was reset to 1 by default" << RESET << std::endl;
    }
    if (num1 == 0){
        std::cout << GREEN << "[!Warn] B was reset to 1 by default" << RESET << std::endl;
    }

    set_a(num1);
    set_b(num2);

    //std::cout << "Created ellipse!" << std::endl; 
}

[[nodiscard]] double tpk2::Ellipse::focal_distance() {
  return 2 * sqrt(pow(a, 2) + pow(b, 2));
}
