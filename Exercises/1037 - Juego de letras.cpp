// https://omegaup.com/arena/problem/jdl/#problems

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimización de IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string p;
    cin >> p;
    int v = 0;

    // Calcula el valor de cada letra y lo suma a v
    for (char c : p) {
        if (c == 'Q' || c == 'A' || c == 'Z') {
            v += 1;
        } else if (c == 'W' || c == 'S' || c == 'X') {
            v += 2;
        } else if (c == 'E' || c == 'D' || c == 'C') {
            v += 3;
        } else if (c == 'R' || c == 'F' || c == 'V') {
            v += 4;
        } else if (c == 'T' || c == 'G' || c == 'B') {
            v += 5;
        } else if (c == 'Y' || c == 'H' || c == 'N') {
            v += 6;
        } else if (c == 'U' || c == 'J' || c == 'M') {
            v += 7;
        } else if (c == 'I' || c == 'K') {
            v += 8;
        } else if (c == 'O' || c == 'L') {
            v += 9;
        } else if (c == 'P') {
            v += 0;
        }
    }

    cout << v << endl;

    return 0;
}
