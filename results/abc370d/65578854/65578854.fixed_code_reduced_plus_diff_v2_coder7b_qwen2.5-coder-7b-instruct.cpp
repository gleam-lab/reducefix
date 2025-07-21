#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y;
};

bool operator<(const Cell& a, const Cell& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

vector<vector<Cell>> adj(200005);

void add_edge(int u, int v) {
    adj[u].push_back({v / 200005, v % 200005});
    adj[v].push_back({u / 200005, u % 200005});
}

void dfs(vector<bool>& visited, int u) {
    visited[u] = true;
    for (auto& [x, y]: adj[u]) {
        if (!visited[x]) dfs(visited, x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            add_edge((i-1)*w+j, (i-1)*w+j+1);
            add_edge((i-1)*w+j, i*w+j);
        }
    }

    for (int i = 1; i <= h-1; ++i) {
        for (int j = 1; j <= w; ++j) {
            add_edge((i-1)*w+j, i*w+j);
        }
    }

    vector<bool> visited(h*w+1, false);
    dfs(visited, 1);

    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        int node = r*w+c+1;
        if (!visited[node]) {
            visited[node] = true;
            dfs(visited, node);
        } else {
            for (auto& [x, y]: adj[node]) {
                if (!visited[x]) {
                    visited[x] = true;
                    dfs(visited, x);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h*w; ++i) {
        if (!visited[i]) ++ans;
    }

    cout << ans << '\n';

    return 0;
}