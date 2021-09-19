#include <iostream>

#include "struct.h"

#define DEBUG 1

int main(int argc, char const *argv[]) {
  int num1 = 0, num2 = 0;
  std::vector<double> vec;
  lab1::Matrix *matr = new lab1::Matrix;

  try {
    
    matr->input();
    if (DEBUG) {
      matr->print_cords();
      matr->print_matr();
    }

    vec = matr->do_business(0);

    std::cout << YELLOW << "Vec.size = " << vec.size() << RESET << std::endl;
    std::cout << "{";
    for (auto i = 0; i < vec.size(); ++i) {
      std::cout << "   " << vec[i];
    }
    std::cout << "   }" << std::endl;

    
  } catch (const std::invalid_argument &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  } catch (const std::runtime_error &e) {

    //delete matr;
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  delete matr;

  return 0;
}
