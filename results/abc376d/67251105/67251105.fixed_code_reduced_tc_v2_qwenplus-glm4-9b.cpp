#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u); // Ensure undirected graph
    }
    
    vector<int> dist(N, INF); // Use INF for all distances initially
    dist[0] = 0; // Distance from source node 0 to itself is 0
    queue<int> que;
    que.push(0); // Start BFS from node 0

    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int neighbor : G[pos]) {
            if (dist[neighbor] == INF) { // If not visited
                dist[neighbor] = dist[pos] + 1;
                que.push(neighbor);
            }
        }
    }
    
    long long ans = INF;
    for (int i = 1; i < N; ++i) {
        int leafCount = 0;
        for (int neighbor : G[i]) {
            if (dist[neighbor] == INF) { // Check if it's a leaf node
                leafCount++;
            }
        }
        if (leafCount == 1) { // Only one connection means it's a leaf node
            ans = min(ans, dist[i]);
        }
    }

    if (ans == INF) cout << -1 << endl; // If no leaf node was found
    else cout << ans + 1 << endl; // Add 1 to the leaf node's distance as per problem statement

    return 0;
}