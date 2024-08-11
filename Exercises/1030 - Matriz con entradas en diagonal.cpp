// https://omegaup.com/arena/problem/med/#problems

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matriz(m, std::vector<int>(n, 0));
    int contador = 1;

    for (int diag = 0; diag < m + n - 1; ++diag) {
        int fila = diag < n ? 0 : diag - n + 1;
        int columna = diag < n ? diag : n - 1;

        while (fila < m && columna >= 0) {
            matriz[fila][columna] = contador++;
            fila++;
            columna--;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
