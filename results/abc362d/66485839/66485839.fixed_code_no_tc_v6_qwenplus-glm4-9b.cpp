#include <bits/stdc++.h>
using namespace std;
#define int long long 
using vi = vector<int>;

struct DSU {
private:
    vi fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[x] = y;
        sz[y] += sz[x];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    DSU dsu(n + 1);
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        if (dsu.same(x, y)) continue;
        dsu.merge(x, y);
    }
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        edges.emplace_back(i, a[i], 0);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        edges.emplace_back(x, y, c);
    }
    sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
        return get<2>(t1) + get<1>(t1) < get<2>(t2) + get<1>(t2);
    });

    vector<int> dist(n + 1, 1e18);
    int cnt = 0;
    for (int i = 0; i < edges.size(); ++i) {
        auto [u, v, w] = edges[i];
        if (dsu.same(u, v)) {
            cnt++;
            if (cnt == n - 1) break;
            continue;
        }
        dsu.merge(u, v);
    }
    dist[1] = a[1];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(a[1], 1, 0);
    while (!pq.empty()) {
        auto [val, u, d] = pq.top();
        pq.pop();
        if (u == dist[u]) {
            dist[u] = val - d;
            if (u != 1) pq.emplace(val - d, u, d + 1);
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}