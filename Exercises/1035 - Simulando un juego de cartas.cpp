// https://omegaup.com/arena/problem/sjc/#problems

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    
    std::map<std::vector<int>, int> seen;
    int moves = 0;

    while (true) {
        // Si la configuración actual ya se ha visto, detener
        if (seen.count(cards)) {
            std::cout << moves << "\n";
            for (int i = 0; i < n; ++i) {
                std::cout << cards[i] << " ";
            }
            std::cout << "\n";
            break;
        }

        seen[cards] = moves;
        ++moves;

        // Invertir las primeras `a` cartas
        int a = cards[0];
        std::reverse(cards.begin(), cards.begin() + a);
    }

    return 0;
}
