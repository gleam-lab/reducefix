#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define pb push_back

template <typename T>
using V = vector<T>;

struct Edge {
    int u, v, w; // w is the weight of the edge and also the weight of the vertex
    bool operator<(const Edge& e) const {
        return w < e.w; // Sort edges based on the total weight (vertex + edge)
    }
};

struct DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vertices(n + 1);
    vector<Edge> edges;

    for (int i = 1; i <= n; ++i) {
        cin >> vertices[i];
        edges.push_back({i, i, vertices[i]}); // Each vertex is treated as an edge with its own weight
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // Each edge has its own weight
    }

    // Sort all edges including the vertex edges
    sort(edges.begin(), edges.end());

    DSU dsu(n + 1);
    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = vertices[1]; // Distance from vertex 1 to itself is its own weight

    for (Edge& edge : edges) {
        if (dsu.unionSets(edge.u, edge.v)) { // Only process if union is valid (not already connected)
            int u = edge.u, v = edge.v, w = edge.w;
            if (dist[u] != LLONG_MAX && dist[v] != LLONG_MAX) {
                dist[v] = min(dist[v], dist[u] + w); // Check if a shorter path is found
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}