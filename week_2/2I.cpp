#include <cmath>
#include <iostream>
#include <string>

std::string IsPrime(int n);

int main() {
  int n = 0;
  std::cin >> n;
  std::cout << IsPrime(n);
}

std::string IsPrime(int n) {
  int c = 0;
  int n_sqrt = std::sqrt(n);
  for (int i = 2; i <= n_sqrt; i++) {
    if (n % i == 0) {
      c++;
      break;
    }
  }
  std::string ans;
  if (c == 0) {
    ans = "prime\n";
  } else {
    ans = "composite\n";
  }
  return ans;
}