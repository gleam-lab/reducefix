#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const int dir[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

class UnionFind {
public:
    vector<int> par;
    vector<int> rank;
    int components;

    UnionFind(int n) : par(n), rank(n, 0) {
        components = n;
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] > rank[py]) swap(px, py);
        par[px] = py;
        if (rank[px] == rank[py]) rank[py]++;
        components--;
        return true;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;

    UnionFind uf(n * n);
    vector<pair<ll, ll>> pieces(m);

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        pieces[i] = {a, b};
        int pos = a * n + b;
        for (auto &p : dir) {
            ll x = a + p[0], y = b + p[1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                ll neighbor_pos = x * n + y;
                uf.unite(pos, neighbor_pos);
            }
        }
    }

    ll free_cells = n * n - uf.components;
    cout << free_cells << endl;

    return 0;
}