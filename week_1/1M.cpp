#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int f = 0;
  int s = 1;
  int res = 0;
  if (n == 0) {
    std::cout << f;
  } else if (n == 1) {
    std::cout << s;
  } else {
    for (int i = 0; i < n - 1; i++) {
      res = f + s;
      f = s;
      s = res;
    }
    std::cout << res;
  }
  return 0;
}