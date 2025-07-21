#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // Make the graph undirected
    }

    vector<int> dist(N, INF);
    dist[0] = 0; // Start BFS from node 0
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int neighbor : G[node]) {
            if (dist[neighbor] == INF) { // If not visited
                dist[neighbor] = dist[node] + 1;
                que.push(neighbor);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        ans = min(ans, dist[i]);
    }

    if (ans == INF) cout << -1 << endl; // If no node is reachable
    else cout << ans << endl; // Output the shortest distance from node 0 to all other nodes
    return 0;
}