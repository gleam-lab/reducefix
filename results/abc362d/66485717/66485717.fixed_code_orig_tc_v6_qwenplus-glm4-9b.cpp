#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

template <class T>
using V = vector<T>;
using VV = vector<V<T>>;

struct Edge {
    int x, y, c;
    Edge() : x(0), y(0), c(INF) {}
    Edge(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {}
};

struct DSU {
    V<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) return;
        if (size[x_root] < size[y_root]) {
            parent[x_root] = y_root;
            size[y_root] += size[x_root];
        } else {
            parent[y_root] = x_root;
            size[x_root] += size[y_root];
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

const int N = 3e5 + 10;
const int INF = 1e18;
V<Edge> edges;
V<int> graph[N];

void add_edge(int u, int v, int c) {
    edges.pb({u, v, c});
    edges.pb({v, u, c});
}

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> graph[i];
    }

    for (auto& e : edges) {
        int u = e.x, v = e.y, c = e.c;
        add_edge(u, v, c);
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.c < b.c;
    });

    for (auto& e : edges) {
        int u = e.x, v = e.y, c = e.c;
        if (dist[u] != INF && dist[u] + c < dist[v]) {
            dist[v] = dist[u] + c;
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << (dist[i] != INF ? dist[i] : -1) << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}