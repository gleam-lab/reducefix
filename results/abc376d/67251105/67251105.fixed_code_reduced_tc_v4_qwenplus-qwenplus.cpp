#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

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

    // Check if there is a cycle back to node 0 through any neighbor of node 0
    int ans = INF;
    for (int i = 1; i < N; ++i) {
        if (dist[i] != -1) {
            // Check if there's an edge from i to 0
            for (auto x : G[i]) {
                if (x == 0) {
                    ans = min(ans, dist[i]);
                    break;
                }
            }
        }
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans + 1 << '\n';  // Add 1 to include the final edge back to 0
    }

    return 0;
}