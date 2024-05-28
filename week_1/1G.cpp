#include <iostream>

int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  std::cin >> a >> b >> c >> d;
  if (a == 0 && b == 0) {
    std::cout << "INF";
  } else if (b * c == a * d) {
    std::cout << "NO";
  } else if ((-b) % a == 0) {
    std::cout << (-b) / a;
  } else {
    std::cout << "NO";
  }
  return 0;
}