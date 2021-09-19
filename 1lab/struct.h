#ifndef LAB1_STR
#define LAB1_STR

#include <iostream>
#include <vector>

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

namespace lab1 {

struct Item {
  size_t x;
  size_t y;
  double value;
};

//* COO - Coordinate list based matrix
class Matrix {
 public:
  size_t get_height() { return height; }

  size_t get_width() { return width; }

  void set_height(size_t num) { height = num; }

  void set_width(size_t num) { width = num; }

  void input();

  void print_cords();

  void print_matr();

  std::vector<double> do_business(int);

  Matrix();

  ~Matrix();

 private:
  int height, width;
  std::vector<Item *> coords;
};
};  // namespace lab1

#endif