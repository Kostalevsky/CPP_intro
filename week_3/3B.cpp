#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  int size = str.size();
  int res = 0;
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (str[i] == '(') {
      if (counter < 0) {
        res -= counter;
        counter = 1;
      } else {
        counter++;
      }
    } else {
      counter--;
    }
  }
  res += std::abs(counter);
  std::cout << res;
  return 0;
}