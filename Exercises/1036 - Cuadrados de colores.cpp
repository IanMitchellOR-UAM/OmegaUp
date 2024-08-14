// https://omegaup.com/arena/problem/cdc/#problems

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> grid(m, vector<int>(n));

    // Leer la cuadrícula
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int max_g = min(m, n);
    int g = 1, c = 0, d = 0;

    // Probar todos los tamaños de cuadrados posibles
    for (int size = 2; size <= max_g; ++size) {
        set<int> unique_colors;
        int count = 0;

        // Revisar cada subcuadrado de tamaño `size`
        for (int i = 0; i <= m - size; ++i) {
            for (int j = 0; j <= n - size; ++j) {
                bool same_color = true;
                int color = grid[i][j];

                // Verificar si todos los cuadros son del mismo color
                for (int x = 0; x < size; ++x) {
                    for (int y = 0; y < size; ++y) {
                        if (grid[i + x][j + y] != color) {
                            same_color = false;
                            break;
                        }
                    }
                    if (!same_color) break;
                }

                // Si es un cuadrado de un solo color
                if (same_color) {
                    unique_colors.insert(color);
                    count++;
                }
            }
        }

        // Si encontramos cuadrados más grandes de un solo color
        if (count > 0) {
            g = size;
            c = count;
            d = unique_colors.size();
        }
    }

    cout << g << " " << c << " " << d << endl;
    return 0;
}
