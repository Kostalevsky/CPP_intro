#include <cmath>
#include <iomanip>
#include <iostream>

double Perimetr(int x1, int y1, int x2, int y2, int x3, int y3) {
  return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)) +
         std::sqrt(std::pow((x3 - x2), 2) + std::pow((y3 - y2), 2)) +
         std::sqrt(std::pow((x1 - x3), 2) + std::pow((y1 - y3), 2));
}

int main() {
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  int x3 = 0;
  int y3 = 0;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  std::cout << std::fixed << std::setprecision(6)
            << Perimetr(x1, y1, x2, y2, x3, y3);
}