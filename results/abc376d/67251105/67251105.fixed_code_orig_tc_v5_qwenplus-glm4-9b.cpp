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
        u--, v--;
        G[u].push_back(v);
    }

    // Use BFS to find distances from the first vertex
    vector<int> dist(N, INF);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : G[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    // Check for the minimum distance among all vertices that have at least two neighbors
    long long minDist = INF;
    for (int i = 0; i < N; i++) {
        if (G[i].size() >= 2 && dist[i] < minDist) {
            minDist = dist[i];
        }
    }

    // Output the result
    if (minDist == INF) {
        cout << -1 << endl;
    } else {
        cout << minDist << endl;
    }
    return 0;
}