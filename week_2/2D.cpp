#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int **array = new int *[n];

  for (int i = 0; i < n; i++) {
    array[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == n - i - 1) {
        array[i][j] = 1;
      } else if (j > n - i - 1) {
        array[i][j] = 2;
      } else {
        array[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
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