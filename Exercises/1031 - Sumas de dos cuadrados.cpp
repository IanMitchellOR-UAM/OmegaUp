// https://omegaup.com/arena/problem/sdc/#problems

#include <iostream>
#include <cmath>

int count_sum_of_squares(int n) {
    int count = 0;
    for (int a = 0; a * a <= n; ++a) {
        int b2 = n - a * a;
        int b = std::sqrt(b2);
        if (b * b == b2 && a <= b) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << count_sum_of_squares(n) << '\n';
    return 0;
}
