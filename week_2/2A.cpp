// #include <iostream>

// int main() {
//   int n = 0;
//   std::cin >> n;
//   int **array = new int *[n];
//   for (int i = 0; i < n; i++) {
//     array[i] = new int[n];
//   }
//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         array[i][j] = 0;
//       }
//     }



//     for (int i = 0; i < n; i++) {
//       delete[] array[i];
//     }
//     delete[] array;

//     return 0;
//   }

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  const int c_n = n;
  int matrix[50][50]{0};
  int i = 0, j = 0;
  while (n > 0) {
    int c = i;
    for (int k = 0; k < n; k++) {
      matrix[i][j] = 1;
      j++;
      matrix[c][n - 1] = 1;
      c++;
    }
    i = n - 1;
    j = n - 1;
    for (int k = 0; k < n; k++) {
      matrix[i][j] = 1;
      j--;
    }
    j++;

    for (int k = 0; k < n - 2; k++) {
      matrix[i][j] = 1;
      i--;
    }
    if (n != 1) {
      i++;
      j++;
    }
    matrix[i][j] = 1;
    j++;
    n -= 4;
  }

  for (int k = 0; k < c_n; k++) {
    for (int l = 0; l < c_n; l++) {
      std::cout << matrix[k][l];
    }
    std::cout << "\n";
  }
  return 0;
}

