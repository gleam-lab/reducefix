#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    int shortest_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == 1) {
                shortest_cycle = min(shortest_cycle, dist[u] + 1);
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (shortest_cycle != INT_MAX) {
        cout << shortest_cycle << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}