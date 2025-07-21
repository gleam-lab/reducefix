#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    if (N == 0 || M == 0) {
        cout << -1 << endl;
        return 0;
    }

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

    bool hasPathToAnyNode = false;
    for (int i = 0; i < N; i++) {
        if (dist[i] != -1 && i != 0) {
            hasPathToAnyNode = true;
            break;
        }
    }

    if (!hasPathToAnyNode) {
        cout << -1 << endl;
    } else {
        int ans = *max_element(dist.begin(), dist.end());
        cout << ans + 1 << endl;
    }

    return 0;
}