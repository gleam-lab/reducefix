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

    // BFS from node 0 to compute shortest distances
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int nex : G[pos]) {
            if (dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                que.push(nex);
            }
        }
    }

    // Check if any cycle back to node 0 exists via other nodes
    int ans = INF;
    for (int i = 1; i < N; ++i) {
        if (dist[i] != -1) {
            // Check if there's an edge from i back to 0
            for (int neighbor : G[i]) {
                if (neighbor == 0) {
                    ans = min(ans, dist[i]);
                    break;
                }
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans + 1 << endl; // +1 for the final edge back to 0
    }

    return 0;
}