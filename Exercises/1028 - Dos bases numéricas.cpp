// https://omegaup.com/arena/problem/dbn/#problems

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long convertToDecimal(const string &num, int base) {
    long long decimal = 0;
    long long power = 1;
    for (int i = num.length() - 1; i >= 0; --i) {
        decimal += (num[i] - '0') * power;
        power *= base;
    }
    return decimal;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    long long n = -1;
    int p = -1, q = -1;

    for (int i = 2; i <= 10; ++i) {
        long long valueA = convertToDecimal(A, i);
        for (int j = 2; j <= 10; ++j) {
            if (i == j) continue;
            long long valueB = convertToDecimal(B, j);
            if (valueA == valueB) {
                if (n == -1 || valueA < n) {
                    n = valueA;
                    p = i;
                    q = j;
                }
            }
        }
    }

    cout << n << " " << p << " " << q << "\n";

    return 0;
}
