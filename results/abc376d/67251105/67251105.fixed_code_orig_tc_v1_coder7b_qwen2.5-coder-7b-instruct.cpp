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

    // Step 1: Find the farthest node from node 0
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

    // Find the farthest node from the found node
    int farthestNode = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > dist[farthestNode]) {
            farthestNode = i;
        }
    }

    // Step 2: Perform BFS from the farthest node to find the longest path
    fill(dist.begin(), dist.end(), -1);
    que.push(farthestNode);
    dist[farthestNode] = 0;
    int maxDist = 0;
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] != -1) continue;
            que.push(nex);
            dist[nex] = dist[pos] + 1;
            maxDist = max(maxDist, dist[nex]);
        }
    }

    // If the maximum distance is less than N-1, then there is no path that visits every node exactly once
    if (maxDist < N - 1) {
        cout << -1 << endl;
    } else {
        cout << maxDist + 1 << endl;
    }

    return 0;
}