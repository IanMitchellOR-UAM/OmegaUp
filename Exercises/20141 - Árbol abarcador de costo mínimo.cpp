// https://omegaup.com/arena/problem/Arbol-abarcador-de-costo-minimo/#problems

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

std::vector<int> parent, rank;

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rank[u] < rank[v])
            std::swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    std::sort(edges.begin(), edges.end());

    parent.resize(N);
    rank.resize(N, 0);
    for (int i = 0; i < N; i++)
        parent[i] = i;

    int mst_cost = 0;
    for (const auto &edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            mst_cost += edge.weight;
            unionSets(edge.u, edge.v);
        }
    }

    std::cout << mst_cost << "\n";

    return 0;
}
