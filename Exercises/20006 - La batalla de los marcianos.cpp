// https://omegaup.com/arena/problem/La-batalla-de-los-marcianos/#problems

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>

struct Marciano {
    std::string nombre;
    int fuerza;
    int edad;
    int index;
};

struct Comparator {
    bool operator()(const Marciano& a, const Marciano& b) const {
        if (a.fuerza != b.fuerza)
            return a.fuerza < b.fuerza;
        if (a.edad != b.edad)
            return a.edad < b.edad;
        return a.index > b.index;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Marciano> marcianos(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> marcianos[i].nombre >> marcianos[i].fuerza >> marcianos[i].edad;
        marcianos[i].index = i;
    }

    std::priority_queue<Marciano, std::vector<Marciano>, Comparator> pq(marcianos.begin(), marcianos.end());

    while (pq.size() > 1) {
        Marciano top1 = pq.top();
        pq.pop();
        Marciano top2 = pq.top();
        pq.pop();

        if (top1.fuerza == top2.fuerza) {
            std::cout << "Muere " << top1.nombre << "\n";
            std::cout << "Muere " << top2.nombre << "\n";
        } else {
            std::cout << "Muere " << top2.nombre << "\n";
            top1.fuerza -= top2.fuerza;
            pq.push(top1);
        }
    }

    return 0;
}
