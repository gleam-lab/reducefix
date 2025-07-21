#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (rank[u] > rank[v]) swap(u, v);
            parent[u] = v;
            if (rank[u] == rank[v]) rank[v]++;
        }
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    UnionFind uf(h * w);
    set<pair<int, pair<int, int>>> pq;
    vector<bool> visited(h * w, false);

    auto getIdx = [&](int x, int y) { return x * w + y; };

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            pq.insert({grid[i][j], {i, j}});
        }
    }

    vector<int> result(y, 0);
    int ans = 0, cnt = 0;

    for (int level = 1; level <= y; ++level) {
        while (!pq.empty() && pq.begin()->first <= level) {
            auto [_, pos] = *pq.begin();
            pq.erase(pq.begin());
            int x = pos.first, y = pos.second;
            if (visited[getIdx(x, y)]) continue;
            visited[getIdx(x, y)] = true;
            cnt++;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] <= level && !visited[getIdx(nx, ny)]) {
                    uf.unite(getIdx(x, y), getIdx(nx, ny));
                }
            }
        }

        int root = uf.find(getIdx(0, 0));
        ans = max(ans, cnt);
        result[level - 1] = ans;
    }

    for (int i = 0; i < y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}