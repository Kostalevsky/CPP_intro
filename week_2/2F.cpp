#include <iostream>

int Gcd(int num1, int num2);

int main() {
  int array_size = 0;
  std::cin >> array_size;
  int *array = new int[array_size];
  for (int i = 0; i < array_size; i++) {
    int num = 0;
    std::cin >> num;
    array[i] = num;
  }
  for (int i = 0; i < array_size - 1; i++) {
    array[i + 1] = Gcd(array[i + 1], array[i]);
  }
  std::cout << array[array_size - 1];
  delete[] array;
  return 0;
}

int Gcd(int num1, int num2) {
  while (num2 > 0) {
    num1 %= num2;
    std::swap(num1, num2);
  }
  return num1;
}