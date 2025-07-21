#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
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
void solve() {
    // Assuming this is the function to handle the main logic for the problem.
    // This function should be filled to solve the problem as described.
}

constexpr int N = 3e5 + 10;
constexpr i64 inf = 1e10;
priority_queue<pair<i64, int>> pq;
V<pair<int, int>> g[N];
void solve2() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    V<i64> d(n + 1, inf);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    pq.emplace(a[1], 1); // Priority queue for Dijkstra's algorithm with vertex and its starting weight
    while (!pq.empty()) {
        auto [w, x] = pq.top();
        pq.pop();
        if (d[x] < w) continue;
        for (auto [y, c] : g[x]) {
            i64 weight = w + c + a[y];
            if (weight < d[y]) {
                d[y] = weight;
                pq.emplace(weight, y);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "" : " ");
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