#include <iostream>

void Sort(int *begin, int *end);

int main() {
  int array_size = 0;
  int num = 0;
  std::cin >> array_size;
  int *array = new int[array_size];
  for (int i = 0; i < array_size; i++) {
    std::cin >> num;
    array[i] = num;
  }
  Sort(array, array + array_size);
  for (int i = 0; i < array_size - 1; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << array[array_size - 1];
  delete[] array;
  return 0;
}

void Sort(int *begin, int *end) {
  int array_size = end - begin + 1;
  for (int i = 0; i < array_size - 1; i++) {
    for (int j = 0; j < array_size - i - 2; j++) {
      if (begin[j + 1] < begin[j]) {
        int temp = begin[j];
        begin[j] = begin[j + 1];
        begin[j + 1] = temp;
      }
    }
  }
}