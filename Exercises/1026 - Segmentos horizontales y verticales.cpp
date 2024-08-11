// https://omegaup.com/arena/problem/shv/#problems

#include <iostream>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int h1 = (y1 == y2) ? 1 : 0; // Verifica si el primer segmento es horizontal
    int h2 = (y3 == y4) ? 1 : 0; // Verifica si el segundo segmento es horizontal

    int x = -1, y = -1; // Inicializa x e y en -1 para indicar que no hay intersección

    // Verifica si los segmentos son perpendiculares y se cruzan
    if ((h1 == 1 && h2 == 0 && x1 <= x3 && x2 >= x3 && y3 <= y1 && y4 >= y1) || 
        (h1 == 0 && h2 == 1 && x3 <= x1 && x4 >= x1 && y1 <= y3 && y2 >= y3)) {
        x = (h1 == 1) ? x3 : x1;
        y = (h1 == 1) ? y1 : y3;
    }

    cout << h1 << " " << h2 << " " << x << " " << y << "\n";

    return 0;
}
