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

    bool found = false;
    for (int nex : G[1]) {
        if (nex == 0) {
            found = true;
            break;
        }
    }

    if (found && dist[1] != -1) {
        cout << dist[1] + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}