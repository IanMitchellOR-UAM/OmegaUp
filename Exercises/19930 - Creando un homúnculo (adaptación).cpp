// https://omegaup.com/arena/problem/Creando-un-homunculo-adaptacion/#problems

#include <iostream>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N;
    std::unordered_set<int> materiales;

    for (int i = 0; i < N; ++i) {
        int material;
        std::cin >> material;
        materiales.insert(material);
    }

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int material;
        std::cin >> material;
        if (materiales.count(material)) {
            std::cout << "SI\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
