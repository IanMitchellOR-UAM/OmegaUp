// https://omegaup.com/arena/problem/Torneo-de-listas-ordenadas/#problems

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> leer_lista(int n) {
  vector<int> lista(n);
  for (int i = 0; i < n; i++) {
    cin >> lista[i];
  }
  return lista;
}

void imprimir_lista(const vector<int> &lista) {
  for (int x : lista) {
    cout << x << " ";
  }
  cout << "\n";
}

pair<int, int> torneo_binario(vector<vector<int>> &listas, bool imprimir) {
  int l = listas.size();
  int n = listas[0].size();
  vector<vector<int>> torneo(log2(l) + 1);
  torneo[0] = vector<int>(l);
  for (int i = 0; i < l; i++) {
    if (listas[i].empty()) {
      torneo[0][i] = -1;
    } else {
      torneo[0][i] = listas[i][0];
    }
  }

  for (int i = 1; i < torneo.size(); i++) {
    int m = torneo[i-1].size() / 2;
    torneo[i] = vector<int>(m);
    for (int j = 0; j < m; j++) {
      int a = torneo[i-1][2*j];
      int b = torneo[i-1][2*j+1];
      if (a == -1) {
        torneo[i][j] = b;
      } else if (b == -1) {
        torneo[i][j] = a;
      } else {
        torneo[i][j] = min(a, b);
      }
    }
  }
  
  if (imprimir) {
    for (const auto &fase : torneo) {
      imprimir_lista(fase);
    }
  }

  int ganador = -1;
  int extraido = torneo.back()[0];
  
  for (int i = 0; i < l; i++) {
    if (!listas[i].empty() && listas[i][0] == extraido) {
      ganador = i;
      break;
    }
  }

  return {ganador, extraido};
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, n, k;
  
  cin >> l >> n >> k;
  
  vector<vector<int>> listas(l);
  
  
  for (int i = 0; i < l; i++) {
    listas[i] = leer_lista(n);
  }

  
   for (int i = 0; i < k-1; i++) {
     auto [ganador, extraido] = torneo_binario(listas, false); 
     listas[ganador].erase(listas[ganador].begin()); 
   }

   auto [ganador_final, extraido_final] = torneo_binario(listas, true); 

}
