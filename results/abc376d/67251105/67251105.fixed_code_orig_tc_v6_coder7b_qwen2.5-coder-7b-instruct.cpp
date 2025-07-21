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
        G[v].push_back(u); // Change direction to find nodes that can reach 0
    }
    vector<int> dist(N, -1);
    queue<pair<int, int>> que;
    que.push({N - 1, 0}); // Start from node N-1 (which corresponds to node 0 in the problem statement)
    dist[N - 1] = 0;
    while (!que.empty()) {
        int pos = que.front().first;
        int d = que.front().second;
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] != -1) continue;
            que.push({nex, d + 1});
            dist[nex] = d + 1;
        }
    }
    int ans = 100000000;
    for (int i = 0; i < N; i++) {
        if (dist[i] != -1 && i != 0) { // Check if node i can reach 0 and is not node 0 itself
            ans = min(ans, dist[i]);
        }
    }
    if (ans == 100000000) cout << -1 << endl;
    else cout << ans + 1 << endl;
    return 0;
}