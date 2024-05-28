#include <iostream>

int main() {
  int x = 0;
  std::cin >> x;
  for (int i = 2; i <= x; i++) {
    if (x % i == 0) {
      std::cout << i << "\n";
      break;
    }
  }
  return 0;
}