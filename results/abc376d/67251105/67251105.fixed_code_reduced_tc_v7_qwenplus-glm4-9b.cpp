#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // Assuming undirected graph
    }
    
    vector<int> dist(N, INF);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        
        for (int neighbor : G[pos]) {
            if (dist[neighbor] > dist[pos] + 1) {
                dist[neighbor] = dist[pos] + 1;
                que.push(neighbor);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        if (dist[i] != INF && dist[i] < ans) {
            ans = dist[i];
        }
    }
    
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}