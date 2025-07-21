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
    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    
    // Perform BFS to find all reachable nodes from node 0
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] != -1) continue;
            que.push(nex);
            dist[nex] = dist[pos] + 1;
        }
    }

    // Check if there is any node that can reach node 0
    bool hasPath = false;
    for (int i = 0; i < N; i++) {
        if (dist[i] != -1) {
            hasPath = true;
            break;
        }
    }

    if (hasPath) {
        int ans = 100000000;
        for (int i = 1; i < N; i++) {
            if (dist[i] != -1) {
                ans = min(ans, dist[i]);
            }
        }
        if (ans == 100000000) cout << -1 << endl;
        else cout << ans + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}