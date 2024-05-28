#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> vec(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0) {
        vec[i][j] = 1;
      } else {
        vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << "\n";
  }
}