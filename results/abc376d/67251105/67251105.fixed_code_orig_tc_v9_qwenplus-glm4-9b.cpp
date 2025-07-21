#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

void bfs(int start, vector<vector<int>>& G, vector<int>& dist, int n) {
    dist.assign(n, INF);
    queue<int> que;
    que.push(start);
    dist[start] = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v : G[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    vector<int> dist(N);
    bfs(0, G, dist, N);

    int minDist = INF;
    for (int i = 1; i < N; ++i) {
        if (!G[i].empty() && dist[i] != INF) {
            minDist = min(minDist, dist[i]);
        }
    }

    if (minDist == INF) {
        cout << -1 << endl;
    } else {
        cout << minDist << endl;
    }

    return 0;
}