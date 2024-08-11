// https://omegaup.com/arena/problem/Rotando-un-arreglo/#problems

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    cin >> M;
    int offset = 0;

    for (int i = 0; i < M; ++i) {
        char op;
        int k;
        cin >> op >> k;

        if (op == 'L') {
            offset = (offset + k) % N;
        } else if (op == 'R') {
            offset = (offset - k + N) % N;
        } else if (op == 'I') {
            int index = (offset + k) % N;
            if (index < 0) {
                index += N;
            }
            cout << arr[index] << "\n";
        }
    }

    return 0;
}
