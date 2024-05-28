#include <iostream>

void Towers(int n, int from, int to, int temp) {
  if (n == 1) {
    std::cout << n << " " << from << " " << to << "\n";
    return;
  }
  Towers(n - 1, from, temp, to);
  std::cout << n << " " << from << " " << to << "\n";
  Towers(n - 1, temp, to, from);
}

int main() {
  int num = 0;
  std::cin >> num;
  Towers(num, 1, 3, 2);
  return 0;
}
