#include <bits/stdc++.h>
using namespace std;

#define INT long long
#define PBK push_back

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<V<T>>;

struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        int root = x;
        while (root != fa[root]) {
            root = fa[root];
        }
        while (x != root) {
            int nex = fa[x];
            fa[x] = fa[fa[x]];
            x = nex;
        }
        return root;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int x, y, c;
    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

INT N, M;
V<int> A;
V<V<int>> adj;
V<VI128> d;

void dijkstra(int src) {
    priority_queue<pair<INT, INT>, V<pair<INT, INT>>, greater<>> pq;
    pq.push({0, src});
    d[src] = {0, A[src]};
    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (weight > d[u][0]) continue;
        for (auto &[v, w] : adj[u]) {
            INT nextWeight = weight + w + A[v];
            if (d[v].empty() || nextWeight < d[v][0]) {
                d[v] = {nextWeight, A[v]};
                pq.push({nextWeight, v});
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    A.resize(N + 1);
    adj.resize(N + 1);
    d.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; ++i) {
        INT u, v, w;
        cin >> u >> v >> w;
        adj[u].PBK({v, w});
        adj[v].PBK({u, w});
    }

    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << d[i][0] << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}