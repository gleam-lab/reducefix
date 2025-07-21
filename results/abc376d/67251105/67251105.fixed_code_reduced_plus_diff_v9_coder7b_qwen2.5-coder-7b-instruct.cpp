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

    // Initialize distance array with infinity
    vector<int> dist(N, INF);
    dist[0] = 0;
    queue<int> que;
    que.push(0);

    // Perform BFS to find all reachable nodes from node 0
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int next : G[pos]) {
            if (dist[next] != INF) continue;
            dist[next] = dist[pos] + 1;
            que.push(next);
        }
    }

    // Check if there is a path from node 0 to any other node
    bool hasPath = false;
    for (int i = 1; i < N; i++) {
        if (dist[i] != INF) {
            hasPath = true;
            break;
        }
    }

    if (!hasPath) {
        cout << -1 << endl;
    } else {
        int ans = *max_element(dist.begin(), dist.end());
        cout << ans << endl;
    }

    return 0;
}