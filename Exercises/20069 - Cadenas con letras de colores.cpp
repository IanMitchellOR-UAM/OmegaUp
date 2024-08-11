// https://omegaup.com/arena/problem/Cadenas-con-letras-de-colores/#problems

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    // Inicializamos los colores disponibles y el número de letras.
    int letras = 26;
    int colores = 3;

    // dp[i][j] representará el número de cadenas válidas de longitud i que terminan en el color j.
    vector<vector<long long>> dp(N + 1, vector<long long>(colores, 0));

    // Para cadenas de longitud 1, podemos tener cualquier letra de cualquier color.
    for (int i = 0; i < colores; ++i) {
        dp[1][i] = letras;
    }

    // Llenamos el dp para longitudes de 2 hasta N.
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < colores; ++j) {
            dp[i][j] = (dp[i-1][(j+1)%colores] + dp[i-1][(j+2)%colores]) * (letras - (i-1));
        }
    }

    // Sumamos todas las combinaciones posibles para cadenas de longitud N.
    long long result = 0;
    for (int i = 0; i < colores; ++i) {
        result += dp[N][i];
    }

    cout << result << "\n";
    return 0;
}
