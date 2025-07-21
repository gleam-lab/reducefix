#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u); // Add edge in both directions for an undirected graph
    }

    vector<int> dist(N, INF);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (int next : G[pos]) {
            if (dist[next] == INF) {
                dist[next] = dist[pos] + 1;
                que.push(next);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        bool has_neighbors = false;
        for (int next : G[i]) {
            if (next != i - 1 && next != i + 1) { // Ensure the node has neighbors other than the previous and next node
                has_neighbors = true;
                break;
            }
        }
        if (has_neighbors) {
            ans = min(ans, dist[i]);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans + 1 << endl; // Output the length of the shortest valid path plus one
    }
    return 0;
}