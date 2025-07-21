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
        G[v].push_back(u); // Since the graph is undirected, add both u to v and v to u
    }
    vector<int> dist(N, INF);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int next = G[pos][i];
            if (dist[next] > dist[pos] + 1) {
                dist[next] = dist[pos] + 1;
                que.push(next);
            }
        }
    }
    int ans = INF;
    for (int i = 1; i < N; i++) {
        if (dist[i] != INF && dist[i] != 0) { // Exclude isolated and source vertex
            ans = min(ans, dist[i]);
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}