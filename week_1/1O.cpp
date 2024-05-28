#include <iostream>
#include <numeric>

int main() {
  int num = 0;
  int denom = 0;
  std::cin >> num >> denom;
  int nod = std::gcd(num, denom);
  std::cout << num / nod << " " << denom / nod << "\n";
}