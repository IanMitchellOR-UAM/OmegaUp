// https://omegaup.com/arena/problem/Pares-e-impares-en-intervalos/#problems

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N;
    std::vector<int> arr(N);
    std::vector<int> even_prefix(N + 1, 0), odd_prefix(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
        even_prefix[i + 1] = even_prefix[i] + (arr[i] % 2 == 0);
        odd_prefix[i + 1] = odd_prefix[i] + (arr[i] % 2 != 0);
    }

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int I, U;
        std::cin >> I >> U;
        int evens = even_prefix[U + 1] - even_prefix[I];
        int odds = odd_prefix[U + 1] - odd_prefix[I];
        std::cout << evens << " " << odds << "\n";
    }

    return 0;
}
