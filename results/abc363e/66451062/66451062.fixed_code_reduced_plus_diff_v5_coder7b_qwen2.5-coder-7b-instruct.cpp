#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] =  {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;

struct Node{
    int x,y,val;
    bool operator <(const Node &a) const{
        return val > a.val;
    }
};

struct UnionFind {
    vector<int> parent, rank, size;
    UnionFind(int n) {
        parent.resize(n+1), rank.resize(n+1, 0), size.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
            if (rank[pu] == rank[pv]) rank[pu]++;
        }
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    UnionFind uf(w * h);

    int total_cells = h * w;
    int sea_level = 0;
    vector<bool> visited(w * h, false);

    auto isValid = [&](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    auto getIdx = [&](int x, int y) {
        return x * w + y;
    };

    for(int level = 1; level <= y; level++) {
        queue<pair<int, int>> q;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(grid[i][j] <= level && !visited[getIdx(i, j)]) {
                    visited[getIdx(i, j)] = true;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if(isValid(nx, ny) && grid[nx][ny] <= level && !visited[getIdx(nx, ny)]) {
                    visited[getIdx(nx, ny)] = true;
                    q.push({nx, ny});
                    uf.unite(getIdx(cx, cy), getIdx(nx, ny));
                }
            }
        }

        total_cells -= uf.getSize(uf.find(getIdx(0, 0)));
        cout << total_cells << endl;
    }

    return 0;
}