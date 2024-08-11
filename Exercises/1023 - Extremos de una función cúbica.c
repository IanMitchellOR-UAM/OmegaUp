// https://omegaup.com/arena/problem/Extremos-de-una-funcion-cubica/#problems

#include <stdio.h>
#include <limits.h>

int main() {
    int a, b, c, d, m, n;
    // Lee los coeficientes a, b, c, d de la función cúbica y los límites m, n del intervalo.
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &m, &n);
    
    // Inicializa p y q para encontrar el valor máximo y mínimo de la función.
    long long p = LLONG_MIN, q = LLONG_MAX;
    int r = m, s = m;
    
    // Itera sobre el intervalo [m, n] para calcular el valor de la función cúbica.
    for (int x = m; x <= n; x++) {
        // Calcula el valor de la función cúbica para x.
        long long fx = (long long)a * x * x * x + (long long)b * x * x + (long long)c * x + d;
        
        // Actualiza el valor máximo y su posición si se encuentra un nuevo máximo.
        if (fx > p) {
            p = fx;
            r = x;
        } else if (fx == p && x < r) {
            r = x;
        }
        
        // Actualiza el valor mínimo y su posición si se encuentra un nuevo mínimo.
        if (fx < q) {
            q = fx;
            s = x;
        } else if (fx == q && x < s) {
            s = x;
        }
    }
    
    // Imprime el valor máximo, el valor mínimo y sus posiciones respectivas.
    printf("%lld %lld %d %d\n", p, q, r, s);
    
    return 0;
}
