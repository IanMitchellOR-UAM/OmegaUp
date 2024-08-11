// https://omegaup.com/arena/problem/tpi/#problems

#include <iostream>
#include <vector>

bool is_triangle(int a, int b, int c) {
    return a + b > c && b + c > a && c + a > b;
}

bool all_odd(int a, int b, int c) {
    return (a % 2 != 0) && (b % 2 != 0) && (c % 2 != 0);
}

bool all_even(int a, int b, int c) {
    return (a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0);
}

int main() {
		std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    int p = 0; // triángulos con lados impares
    int q = 0; // triángulos con lados pares

    for (int a = m; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            for (int c = b; c <= n; ++c) {
                if (is_triangle(a, b, c)) {
                    if (all_odd(a, b, c)) {
                        ++p;
                    }
                    if (all_even(a, b, c)) {
                        ++q;
                    }
                }
            }
        }
    }

    std::cout << p << " " << q << "\n";

    return 0;
}
