#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long int ll;

const int MAX_N = 2e5 + 10;
int parent[MAX_N];
int rank_[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank_[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (rank_[x] < rank_[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank_[x] == rank_[y]) {
            rank_[x]++;
        }
    }
}

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    vector<Edge> edges;
public:
    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    void kruskalMST(int n, int m) {
        sort(edges.begin(), edges.end());
        init(n);
        set<pair<int, int>> result;
        for (auto &edge : edges) {
            int u = edge.u, v = edge.v, w = edge.weight;
            if (find(u) != find(v)) {
                unite(u, v);
                result.insert({w, v});
            }
        }
        for (auto &[weight, vertex] : result) {
            cout << weight << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.kruskalMST(n, m);
    return 0;
}