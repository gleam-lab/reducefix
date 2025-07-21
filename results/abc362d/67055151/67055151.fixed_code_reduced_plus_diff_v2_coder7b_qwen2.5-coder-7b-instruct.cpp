#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vi parent, rank;
    DSU(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(u, v, w);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vl costs(n-1, LLONG_MAX);

    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        int pu = dsu.find(u), pv = dsu.find(v);
        if (pu != pv) {
            dsu.merge(pu, pv);
            costs[u] = min(costs[u], w + a[u]);
            costs[v] = min(costs[v], w + a[v]);
        }
    }

    for (int i = 1; i < n; ++i) {
        costs[i] = min(costs[i], costs[i-1] + a[i]);
    }

    for (int i = 1; i < n; ++i) {
        cout << costs[i] << " ";
    }
    cout << endl;

    return 0;
}