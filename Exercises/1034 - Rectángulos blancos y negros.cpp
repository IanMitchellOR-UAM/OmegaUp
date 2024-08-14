// https://omegaup.com/arena/problem/rbn/#problems

#include <iostream>
#include <vector>

int main() {
  	std::ios_base::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
  
    int m, n;
    std::cin >> m >> n;
    
    std::vector<std::vector<int>> grid(m, std::vector<int>(n));
    
    // Leer la rejilla
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }
    
    int p = 0, q = 0;

    // Contar rectángulos blancos y negros
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i + 1; k < m; ++k) {
                for (int l = j + 1; l < n; ++l) {
                    int a = grid[i][j];
                    int b = grid[i][l];
                    int c = grid[k][j];
                    int d = grid[k][l];
                    if (a == b && b == c && c == d) {
                        if (a == 1) ++p; // Rectángulo blanco
                        else ++q;        // Rectángulo negro
                    }
                }
            }
        }
    }

    std::cout << p << " " << q << "\n";
    return 0;
}
