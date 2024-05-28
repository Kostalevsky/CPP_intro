#include <iostream>

void ReversedSeq(int num);

int main() {
  int num = 0;
  std::cin >> num;
  ReversedSeq(num);
  return 0;
}

void ReversedSeq(int num) {
  if (num > 0) {
    int n = 0;
    std::cin >> n;
    ReversedSeq(num - 1);
    std::cout << n << " ";
  }
}