#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PB push_back

template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;

struct DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (size[x] < size[y]) {
            swap(x, y);
        }
        size[x] += size[y];
        parent[y] = x;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

struct Edge {
    int from, to, cost;

    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

int N, M;
V<int> vertexWeights;
VV<Edge> graph;

void readInput() {
    cin >> N >> M;
    vertexWeights.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> vertexWeights[i];
    }

    for (int i = 0; i < M; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].PB({from, to, cost});
        graph[to].PB({to, from, cost});
    }
}

void solve() {
    // Kruskal's algorithm with union-find to find the MST
    DSU dsu(N + 1);
    V<Edge> edges;
    for (int i = 1; i <= N; ++i) {
        for (const auto& [to, cost] : graph[i]) {
            edges.PB({i, to, cost + vertexWeights[i] + vertexWeights[to]});
        }
    }

    sort(edges.begin(), edges.end());

    // Use a min-heap to process edges by cost
    priority_queue<Edge, V<Edge>, greater<Edge>> minHeap;
    for (const auto& edge : edges) {
        minHeap.push(edge);
    }

    V<int> minPath(N + 1, LLONG_MAX);
    minPath[1] = 0;

    while (!minHeap.empty()) {
        auto [u, v, cost] = minHeap.top();
        minHeap.pop();

        if (minPath[u] + cost < minPath[v]) {
            minPath[v] = minPath[u] + cost;
        }

        if (u != 1 && v != 1 && !dsu.connected(u, 1)) {
            dsu.unite(u, 1);
        }

        if (u != 1 && v != 1 && !dsu.connected(v, 1)) {
            dsu.unite(v, 1);
        }
    }

    // Output the minimum path costs for vertices 2 through N
    for (int i = 2; i <= N; ++i) {
        cout << minPath[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    readInput();
    solve();
    return 0;
}