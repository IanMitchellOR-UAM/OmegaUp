// https://omegaup.com/arena/problem/El-edificio-de-los-vecinos-curio/#problems

#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<long long> vector;
    std::unordered_set<long long> vectorTwo;
    std::vector<long long> results;
    std::vector<long long> resultsTwo;

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> universo(n);
    n = 1;
    for (auto& element : universo) {
        element = n++;
    }

    while (m--) {
        long long current_number, current_number_two;
        std::cin >> current_number >> current_number_two;
        vector.insert(current_number);
        vectorTwo.insert(current_number_two);
    }

    for (const auto& element : universo) {
        if (vectorTwo.find(element) == vectorTwo.end()) {
            results.push_back(element);
        }
    }

    for (const auto& element : universo) {
        if (vector.find(element) == vector.end()) {
            resultsTwo.push_back(element);
        }
    }

    std::sort(results.begin(), results.end());
    std::sort(resultsTwo.begin(), resultsTwo.end());

    std::cout << results.size() << " " << resultsTwo.size() << '\n';

    for (const auto& element : results) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    for (const auto& element : resultsTwo) {
        std::cout << element << ' ';
    }

    return 0;
}
