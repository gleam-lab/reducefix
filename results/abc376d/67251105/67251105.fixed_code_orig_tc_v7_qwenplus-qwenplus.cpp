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

    // BFS to find shortest distances from node 0
    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] != -1) continue;
            dist[nex] = dist[pos] + 1;
            que.push(nex);
        }
    }

    // Check for any cycle back to node 0 from other nodes
    int ans = INF;
    for (int i = 1; i < N; i++) {
        for (auto x : G[i]) {
            if (x == 0 && dist[i] != -1) {
                ans = min(ans, dist[i] + 1);
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}