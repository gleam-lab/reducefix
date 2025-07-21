#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);  // Make sure to add both u and v to each other's adjacency lists
    }
    vector<int> dist(N, INF);
    dist[0] = 0;  // Start BFS from node 0
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int adj : G[pos]) {
            if (dist[adj] == INF) {  // Ensure we only process nodes not visited
                dist[adj] = dist[pos] + 1;
                que.push(adj);
            }
        }
    }

    // Find the smallest distance to any node that has at least one connected node
    int ans = INF;
    for (int i = 0; i < N; i++) {
        bool ok = false;
        for (int adj : G[i]) {
            if (dist[adj] != INF) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans = min(ans, dist[i]);
        }
    }

    // If no such node exists, return -1; otherwise, return the smallest distance + 1
    if (ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl;

    return 0;
}