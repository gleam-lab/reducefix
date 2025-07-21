#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> adj;
vector<int> dist;

void bfs() {
    queue<int> q;
    bitset<200001> visited;
    dist[1] = 0;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    dist.assign(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bfs();

    if (dist[1] == INF)
        cout << -1 << endl;
    else
        cout << dist[1] << endl;

    return 0;
}