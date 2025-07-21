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

class UnionFind {
public:
    vector<int> parent, rank, size;
    int n;

    UnionFind(int n) : n(n), parent(n), rank(n, 1), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            rank[pu]++;
            size[pu] += size[pv];
        }
    }

    bool same(int u, int v) {
        return find(u) == find(v);
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

    bool vis[MAXN][MAXN];
    memset(vis, false, sizeof(vis));

    priority_queue<Node> q;
    for (int i = 0; i < h; i++) {
        q.push({i, 0, grid[i][0]});
        q.push({i, w - 1, grid[i][w - 1]});
        vis[i][0] = vis[i][w - 1] = true;
    }
    for (int i = 1; i < w - 1; i++) {
        q.push({0, i, grid[0][i]});
        q.push({h - 1, i, grid[h - 1][i]});
        vis[0][i] = vis[h - 1][i] = true;
    }

    UnionFind dsu(h * w);
    int res = h * w;
    int level = 1;

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    for (int level = 1; level <= y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
            int x = cur.x, y = cur.y, val = cur.val;
            if (seen[x][y]) continue;
            seen[x][y] = true;
            res--;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny] <= level) {
                    vis[nx][ny] = true;
                    dsu.unite(x * w + y, nx * w + ny);
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}