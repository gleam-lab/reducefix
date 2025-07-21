#include <bits/stdc++.h>
using namespace std;

#define INT signed
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

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

using i64 = long long;

void solve2() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    vector<i64> d(n + 1, inf);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    priority_queue<Node> pq;
    pq.emplace(1, d[1] = a[1]);

    while (pq.size()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;

        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.emplace(y, d[y]);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}