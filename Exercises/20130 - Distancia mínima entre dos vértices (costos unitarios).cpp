// https://omegaup.com/arena/problem/Distancia-minima-entre-dos-vert1/#problems

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N, M, E, S;
    cin >> N >> M >> E >> S;

    // Definir una lista de adyacencia para representar el grafo
    vector<vector<int>> adj(N);

    // Leer las aristas
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Algoritmo de Dijkstra o BFS para encontrar la distancia mínima
    vector<int> dist(N, numeric_limits<int>::max());
    queue<int> q;

    dist[E] = 0;
    q.push(E);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == numeric_limits<int>::max()) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << dist[S] << endl;

    return 0;
}
