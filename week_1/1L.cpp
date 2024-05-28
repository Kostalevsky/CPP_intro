#include <iostream>

int main() {
  int64_t num = 0;
  int sum = 0;
  std::cin >> num;
  while (num > 0) {
    int n = num % 10;
    sum += n;
    num /= 10;
  }
  std::cout << sum;
}