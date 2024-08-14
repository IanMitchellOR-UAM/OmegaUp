// https://omegaup.com/arena/problem/ddc/#problems

#include <iostream>

using namespace std;

int countSquareDifferences(int n) {
    int count = 0;
    for (int x = 1; x * x <= n; ++x) {
        if (n % x == 0) {
            int y = n / x;
            if ((y - x) % 2 == 0) {  // Deben tener la misma paridad
                int a = (y + x) / 2;
                int b = (y - x) / 2;
                if (a >= b && b >= 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    cout << countSquareDifferences(n) << endl;
    return 0;
}
