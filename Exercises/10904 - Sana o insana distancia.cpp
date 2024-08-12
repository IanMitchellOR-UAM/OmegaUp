// https://omegaup.com/arena/problem/Sana-o-insana-distancia/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  	cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  
    int xa, ya, xb, yb, d;

    cout << "";
    cin >> xa >> ya >> xb >> yb;

    d = sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));

    if (d >= 150) {
        cout << "sana";
    } else {
        cout << "insana";
    }

    return 0;
}
