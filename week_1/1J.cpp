#include <iostream>

int main() {
  int n = 0;
  int num = 0;
  int sum = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> num;
    sum += num;
  }
  std::cout << sum << "\n";
  return 0;
}