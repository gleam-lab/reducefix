#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 202020;
vector<vector<int>> adj(MAXN);
bool seen[MAXN];
ll area[MAXN];

ll dfs(int v) {
    seen[v] = true;
    ll current_area = 1;
    for (int u : adj[v]) {
        if (!seen[u]) {
            current_area += dfs(u);
        }
    }
    return current_area;
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    ll total_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            total_area += a[i][j];
        }
    }

    for (int i = 0; i < MAXN; ++i) {
        adj[i].clear();
        area[i] = 0;
        seen[i] = false;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] > 0) {
                int v = a[i][j];
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                            if (a[ni][nj] == 0) {
                                adj[v].push_back(a[ni][nj]);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= total_area; ++i) {
        if (!seen[i]) {
            area[i] = dfs(i);
        }
    }

    for (int y_ = 0; y_ < y; ++y_) {
        for (int i = 1; i <= total_area; ++i) {
            for (int u : adj[i]) {
                if (area[u] == 0) {
                    adj[i].erase(remove(adj[i].begin(), adj[i].end(), u), adj[i].end());
                }
            }
        }
        for (int i = 1; i <= total_area; ++i) {
            if (adj[i].empty()) {
                seen[i] = true;
            }
        }
        ll remaining_area = 0;
        for (int i = 1; i <= total_area; ++i) {
            if (!seen[i]) {
                remaining_area += dfs(i);
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}