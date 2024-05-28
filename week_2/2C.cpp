#include <iostream>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int **array = new int* [n];
  for (int i = 0; i < n; i++) {
    array[i] = new int[m];
  }
  int i = 0;
  int j = 0;
  int number = 0;
  int count = n * m;
  while (number < count) {
    array[i][j] = number;
    number++;
    if (j == 0) {
      if (i + j + 1 >= m) {
        j = m - 1;
        i = i - m + 2;
      } else {
        j = i + j + 1;
        i = 0;
      }
    } else if (i == n - 1) {
      if (m - j - n - 1 >= 0) {
        j = i + j + 1;
        i = 0;
      } else {
        i = j + n - m + 1;
        j = m - 1;
      }
    } else {
      j -= 1;
      i += 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << "\n";
  }
  for (int i = 0; i < n; i++) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}