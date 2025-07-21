#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1); // Adjusted size to accommodate 1-based indexing
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // Add an undirected edge
    }
    vector<int> dist(N + 1, INF); // Initialize distances to INF
    dist[1] = 0; // Start BFS from node 1
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int& nex : G[pos]) {
            if (dist[nex] == INF) { // Only enqueue nodes with unvisited distance
                dist[nex] = dist[pos] + 1;
                que.push(nex);
            }
        }
    }
    int ans = INF; // Initialize to INF for comparison
    for (int i = 2; i <= N; ++i) { // Start from 2 as 1 is already visited
        bool hasEdge = false;
        for (int& next : G[i]) {
            if (next != 1) hasEdge = true; // Check if there's an edge to a different node
            break;
        }
        if (hasEdge) {
            ans = min(ans, dist[i]);
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl; // +1 to convert from 0-based to 1-based index
    return 0;
}