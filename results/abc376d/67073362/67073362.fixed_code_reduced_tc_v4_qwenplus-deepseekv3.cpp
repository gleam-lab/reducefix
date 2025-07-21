#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = INF;
    for (int neighbor : adj[1]) {
        queue<int> q;
        vector<int> dist(n + 1, INF);
        dist[neighbor] = 1;
        q.push(neighbor);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    cout << (min_cycle == INF ? -1 : min_cycle) << endl;
    return 0;
}