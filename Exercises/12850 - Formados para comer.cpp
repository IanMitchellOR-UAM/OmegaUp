// https://omegaup.com/arena/problem/Formados-para-comer/

#include <iostream>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::deque<std::string> t, r;
    int n;

    std::cin >> n;
    while (n--) {
        std::string i, v;

        std::cin >> i >> v;
        if (i == "LLEGA") {
            t.push_back(v);
        }
        else if (v == "TACO") {
            r.push_back(t.front());
            t.pop_front();
        }
        else {
            r.pop_front();
        }
    }

    for (const auto& e : t) {
        std::cout << e << " ";
    }
    std::cout << "\n";
    for (const auto& e : r) {
        std::cout << e << " ";
    }

    return 0;
}
