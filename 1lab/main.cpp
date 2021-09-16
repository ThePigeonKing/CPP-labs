#include <iostream>

#include "struct.h"

int main(int argc, char const *argv[]) {
  int num1 = 0, num2 = 0;
  std::vector<int> vec;

  try {
    lab1::Matrix *matr = new lab1::Matrix;
    matr->input();
    matr->print_cords();
    matr->print_matr();
    vec = matr->do_business(0);

    std::cout << "Vec.size = " << vec.size() << std::endl;
    std::cout << "{ " << std::endl;
    for (auto i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << "    "; 
    }
    std::cout << std::endl << "}" << std::endl;

    delete matr;
  } catch (const std::invalid_argument &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  return 0;
}
