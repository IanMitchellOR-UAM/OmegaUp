// https://omegaup.com/arena/problem/Extremos-de-una-funcion-cubica/#problems

#include <stdio.h>
#include <limits.h>

int main() {
    int a, b, c, d, m, n;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &m, &n);
    
    long long p = LLONG_MIN, q = LLONG_MAX;
    int r = m, s = m;
    
    for (int x = m; x <= n; x++) {
        long long fx = (long long)a * x * x * x + (long long)b * x * x + (long long)c * x + d;
        
        if (fx > p) {
            p = fx;
            r = x;
        } else if (fx == p && x < r) {
            r = x;
        }
        
        if (fx < q) {
            q = fx;
            s = x;
        } else if (fx == q && x < s) {
            s = x;
        }
    }
    
    printf("%lld %lld %d %d\n", p, q, r, s);
    
    return 0;
}
