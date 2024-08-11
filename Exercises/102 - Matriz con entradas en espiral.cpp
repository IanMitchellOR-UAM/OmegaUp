// https://omegaup.com/arena/problem/mee/#problems

#include <iostream>
#include <vector>

using namespace std;

void generateSpiralMatrix(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n, 0));

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int value = 1;

    while (top <= bottom && left <= right) {
        // Llenar la fila superior
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = value++;
        }
        ++top;

        // Llenar la columna derecha
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = value++;
        }
        --right;

        // Llenar la fila inferior
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = value++;
            }
            --bottom;
        }

        // Llenar la columna izquierda
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = value++;
            }
            ++left;
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    generateSpiralMatrix(m, n);

    return 0;
}
