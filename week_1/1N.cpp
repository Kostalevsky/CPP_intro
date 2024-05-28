#include <iostream>

int main() {
  int a = 0;
  int b = 0;
  int ans = 0;
  std::cin >> a >> b;
  while (a != 0 && b != 0) {
    if (a > b) {
      ans += a / b;
      a %= b;
    } else {
      ans += b / a;
      b %= a;
    }
  }
  std::cout << ans;
}