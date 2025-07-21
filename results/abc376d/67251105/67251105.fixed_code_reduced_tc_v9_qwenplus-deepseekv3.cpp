#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // converting to 0-based
        G[u].push_back(v);
        G[v].push_back(u); // assuming undirected graph
    }

    vector<int> dist(N, -1);
    vector<int> parent(N, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    int ans = INT_MAX;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if(parent[u] != v) { // found a cycle
                ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}