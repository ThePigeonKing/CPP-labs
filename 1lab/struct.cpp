#include "struct.h"

namespace lab1 {

void Matrix::input() {
  double inp = -1;
  Item *new_item;

  std::cout << BLUE << "Enter matrix " << height << "x" << width << "size --->"
            << RESET << std::endl;

  for (auto y = 0; y < width; ++y) {
    for (auto x = 0; x < height; ++x) {
      std::cin >> inp;
      if (inp != 0.0) {
        new_item = new Item;
        new_item->x = x;
        new_item->y = y;
        new_item->value = inp;
        coords.push_back(new_item);
      }
    }
  }
}

void Matrix::print_cords() {
  std::cout << YELLOW << "Coords --> " << RESET << std::endl;
  if (coords.size() == 0) {
    std::cout << RED << "EMPTY!" << RESET << std::endl;
  }
  for (int i = 0; i < coords.size(); ++i) {
    std::cout << "(" << coords[i]->x + 1 << ", " << coords[i]->y + 1 << ") - "
              << coords[i]->value << std::endl;
  }
}

void Matrix::print_matr() {
  int pos = 0;

  std::cout << "--------------------" << std::endl;
  for (auto y = 0; y < width; ++y) {
    for (auto x = 0; x < height; ++x) {
      if (pos == coords.size()) {
        std::cout << "0 ";
        continue;
      }
      if ((x == coords[pos]->x) && (y == coords[pos]->y)) {
        std::cout << coords[pos]->value << " ";
        pos++;
      } else {
        std::cout << "0 ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << "--------------------" << std::endl;
}

// -1 = not found, index = found
int find_coords(std::vector<Item *> coords, int x_to_find, int y_to_find) {
  for (int i = 0; i < coords.size(); ++i) {
    if ((coords[i]->x == x_to_find) && (coords[i]->y == y_to_find)) {
      return i;
    }
  }

  return -1;
}

std::vector<int> Matrix::do_business(int debug = 0) {
  
  int sum = 0, last_y = -1, current_y = 0, pos = 0, index = -1;
  std::vector<int> final;

  if (coords.size() == 0){
    for (auto i = 0; i < height; ++i){
      final.push_back(0);
    }
    return final;
  }

  for (int i = 0; i < height; ++i) {
    if (coords[pos]->y == i) {  // найден элемент такого Y

      while (coords[pos]->y == i) {
        if (coords[pos]->y == 0) {
          index = find_coords(coords, coords[pos]->x, coords.size() - 1);
        } else {
          index = find_coords(coords, coords[pos]->x, coords[pos]->y - 1);
        }
        if (index == -1) {
          sum += coords[pos]->value;
          
        } else if (coords[index]->value < coords[pos]->value) {
          sum += coords[pos]->value;
        }
        pos++;
        if (pos == coords.size()){
          break;
        }
      }
      
      final.push_back(sum);
      sum = 0;
    } else {
      coords.push_back(0);
    }
  }

  return final;
}

}  // namespace lab1
