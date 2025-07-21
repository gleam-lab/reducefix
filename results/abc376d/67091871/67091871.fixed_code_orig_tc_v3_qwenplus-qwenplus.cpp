#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;

ll n, m;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bfs();

    if (dist[1] == -1) {
        cout << -1 << "\n";
    } else {
        cout << dist[1] << "\n";
    }

    return 0;
}