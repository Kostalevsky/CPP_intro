#include <iostream>

int main() {
  int num = 0;
  int max1 = 0;
  int max2 = 0;
  std::cin >> num;
  max1 = num;
  std::cin >> num;
  while (num != 0) {
    if (num >= max1) {
      max2 = max1;
      max1 = num;
    } else if (max2 < num) {
      max2 = num;
    }
    std::cin >> num;
  }
  std::cout << max2;
  return 0;
}