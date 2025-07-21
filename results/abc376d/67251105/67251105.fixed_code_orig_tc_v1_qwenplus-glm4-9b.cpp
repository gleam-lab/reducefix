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
        G[v].push_back(u);
    }
    vector<int> dist(N, INF);
    queue<pair<int, int>> que;
    for (int i = 0; i < N; i++) {
        if (G[i].empty()) {
            que.push({i, 0});
            dist[i] = 0;
        }
    }
    while (!que.empty()) {
        int pos = que.front().first;
        int d = que.front().second;
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] > d + 1) {
                dist[nex] = d + 1;
                que.push({nex, d + 1});
            }
        }
    }
    long long ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dist[i]);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}