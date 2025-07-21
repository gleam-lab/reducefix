#include <bits/stdc++.h>
using namespace std;

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

    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (dist[i] == -1) continue;
        for (int x : G[i]) {
            if (x == 0) {
                if (ans == -1 || dist[i] + 1 < ans) {
                    ans = dist[i] + 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}