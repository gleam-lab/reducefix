#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1100
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val;
    }
};

struct UnionFind {
    vector<int> parent, rank, size;

    UnionFind(int n) : parent(n), rank(n, 1), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        rank[pu] += rank[pv];
        size[pu] += size[pv];
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    UnionFind uf(h * w);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            edges.emplace_back(grid[i][j], make_pair(i, j));
        }
    }
    sort(edges.begin(), edges.end());

    int res = h * w;
    int level = 1;
    set<int> remaining_areas;

    for (auto [height, pos] : edges) {
        int x = pos.first, y = pos.second;
        int idx = x * w + y;
        remaining_areas.insert(idx);

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                int nidx = nx * w + ny;
                if (remaining_areas.count(nidx)) {
                    uf.unite(idx, nidx);
                }
            }
        }
        
        res -= uf.getSize(idx);
        if (res == 0) break;

        cout << res << endl;
    }

    while (level <= y) {
        cout << res << endl;
        level++;
    }

    return 0;
}