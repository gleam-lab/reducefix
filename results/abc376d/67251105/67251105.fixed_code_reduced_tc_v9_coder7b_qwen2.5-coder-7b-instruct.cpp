#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u); // Since the graph is undirected
    }

    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while(!que.empty()) {
        int pos = que.front();
        que.pop();
        for(int next : G[pos]) {
            if(dist[next] != -1) continue;
            dist[next] = dist[pos] + 1;
            que.push(next);
        }
    }

    int ans = INF;
    for(int i = 1; i < N; i++) {
        bool ok = false;
        for(int j : G[i]) {
            if(j == 0) {
                ok = true;
                break;
            }
        }
        if(ok && dist[i] != -1) {
            ans = min(ans, dist[i]);
        }
    }

    if(ans == INF) cout << -1 << '\n';
    else cout << ans + 1 << '\n';

    return 0;
}