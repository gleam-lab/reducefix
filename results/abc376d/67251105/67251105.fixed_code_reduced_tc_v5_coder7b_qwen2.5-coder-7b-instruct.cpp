#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

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

    vector<int> degree(N, 0);
    for (int i = 0; i < N; i++) {
        degree[i] = G[i].size();
    }

    // Find all nodes with exactly one neighbor
    vector<int> special_nodes;
    for (int i = 0; i < N; i++) {
        if (degree[i] == 1) {
            special_nodes.push_back(i);
        }
    }

    // If there are no special nodes, return -1
    if (special_nodes.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // Initialize distances array with INF
    vector<int> dist(N, INF);
    dist[0] = 0;

    // BFS to find the minimum distance to any special node
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] != INF) continue;
            que.push(nex);
            dist[nex] = dist[pos] + 1;
        }
    }

    // Check if any special node is reachable
    bool found = false;
    for (int node : special_nodes) {
        if (dist[node] != INF) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << *min_element(dist.begin(), dist.end()) + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}