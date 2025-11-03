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
using  i64 = long long;
void solve() {

}
struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};
constexpr int N = 3e5 + 10;
priority_queue<Node> pq;
vector<pair<int, int>> g[N];
void solve2() {
    int n, m;
    cin >> n >> m;
    V<i64> a(n + 1, 0);
    vector<i64> d(n + 1, LLONG_MAX);
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
    d[1] = a[1];
    pq.emplace(1, d[1]);
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            i64 new_dist = d[x] + dw + a[y];
            if (new_dist < d[y]) {
                d[y] = new_dist;
                pq.emplace(y, d[y]);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}
INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve2();
    }
    return 0;
}