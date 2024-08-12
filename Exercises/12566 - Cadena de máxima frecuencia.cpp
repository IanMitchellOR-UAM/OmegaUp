// https://omegaup.com/arena/problem/Cadena-de-maxima-frecuencia/

#include <iostream>
#include <cstring>

using namespace std;

int freq[36 * 36 * 36 * 36];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;

    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int prefix = (s[0] >= 'a' ? s[0] - 'a' + 10 : s[0] - '0') * 36
                + (s[1] >= 'a' ? s[1] - 'a' + 10 : s[1] - '0');
        int suffix = (s[3] >= 'a' ? s[3] - 'a' + 10 : s[3] - '0') * 36
                + (s[4] >= 'a' ? s[4] - 'a' + 10 : s[4] - '0');
        freq[prefix * 1296 + suffix]++;
    }

    int max_freq = 0;
    int ans_prefix = 0;
    int ans_suffix = 0;
    for (int i = 0; i < 36 * 36 * 36 * 36; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            ans_prefix = i / 1296;
            ans_suffix = i % 1296;
        }
    }

    cout << char(ans_prefix / 36 + (ans_prefix / 36 < 10 ? '0' : 'a' - 10))
        << char(ans_prefix % 36 + (ans_prefix % 36 < 10 ? '0' : 'a' - 10))
        << "@"
        << char(ans_suffix / 36 + (ans_suffix / 36 < 10 ? '0' : 'a' - 10))
        << char(ans_suffix % 36 + (ans_suffix % 36 < 10 ? '0' : 'a' - 10))
        << " " << max_freq << endl;

    return 0;
}
