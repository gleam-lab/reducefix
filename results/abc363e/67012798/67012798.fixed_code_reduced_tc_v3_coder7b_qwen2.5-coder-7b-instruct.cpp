#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int h, w, y;
int a[MAXN][MAXN], vis[MAXN][MAXN];

vector<int> adj[MAXN * MAXN];
int dfn[MAXN * MAXN], low[MAXN * MAXN], cnt, art[MAXN * MAXN];

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    int child = 0;
    for (auto v : adj[u]) {
        if (!dfn[v]) {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (fa == -1 && child > 1) art[u] = 1;
            else if (fa != -1 && low[v] >= dfn[u]) art[u] = 1;
        } else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    // Build graph
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int id = i * w + j;
            if (i > 0) adj[id].push_back((i - 1) * w + j);
            if (i < h - 1) adj[id].push_back((i + 1) * w + j);
            if (j > 0) adj[id].push_back(i * w + j - 1);
            if (j < w - 1) adj[id].push_back(i * w + j + 1);
        }
    }

    // Tarjan's Algorithm to find articulation points
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(art, 0, sizeof(art));
    cnt = 0;
    for (int i = 0; i < h * w; i++) {
        if (!dfn[i]) dfs(i, -1);
    }

    // Process each year
    for (int t = 1; t <= y; t++) {
        int res = h * w;
        for (int i = 0; i < h * w; i++) {
            if (a[i / w][i % w] <= t) {
                res--;
                for (auto v : adj[i]) {
                    if (a[v / w][v % w] <= t) res--;
                }
            }
        }
        for (int i = 0; i < h * w; i++) {
            if (a[i / w][i % w] <= t && art[i]) res--;
        }
        cout << res << '\n';
    }

    return 0;
}