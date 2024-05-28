#include <iostream>

int main() {
  int n = 0;
  int m = 0;
  int mines = 0;
  std::cin >> n >> m >> mines;
  int **field = new int *[n + 2];

  for (int i = 0; i < n + 2; i++) {
    field[i] = new int[m + 2];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      field[i][j] = 0;
    }
  }

  for (int i = 0; i < mines; i++) {
    int x = 0;
    int y = 0;
    std::cin >> x >> y;
    field[x][y] = -1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (field[i][j] != -1) {
        field[i][j] = (field[i - 1][j] == -1) + (field[i - 1][j - 1] == -1) + (field[i - 1][j + 1] == -1) +
                      (field[i][j - 1] == -1) + (field[i][j + 1] == -1) + (field[i][j] == -1) +
                      (field[i + 1][j - 1] == -1) + (field[i + 1][j + 1] == -1) + (field[i + 1][j] == -1);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (field[i][j] == -1) {
        std::cout << '*' << " ";
      } else {
        std::cout << field[i][j] << " ";
      }
    }
    std::cout << "\n";
  }

  for (int i = 0; i < n + 2; i++) {
    delete[] field[i];
  }

  delete[] field;
  return 0;
}