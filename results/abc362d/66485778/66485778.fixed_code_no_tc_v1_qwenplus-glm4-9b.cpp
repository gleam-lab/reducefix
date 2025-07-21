#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<V<T>>;
struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    V<int> d(n + 1, 1e18);
    DSU dsu(n + 1);
    V<V<pair<int, int>>> g(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }
    
    d[1] = a[1];
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const auto& [next, weight] : g[cur]) {
            int next_weight = d[cur] + weight + a[next];
            if (next_weight < d[next]) {
                d[next] = next_weight;
                q.push(next);
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i < n ? " " : "");
    }
    
    return 0;
}