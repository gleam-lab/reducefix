#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // BFS from node 1
    queue<int> q;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[1] == INF)
        cout << -1 << endl;
    else
        cout << dist[1] << endl;

    return 0;
}