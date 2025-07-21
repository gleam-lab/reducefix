#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = INT_MAX;
    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q;
    
    // Initialize BFS from node 1's neighbors
    for (int v : adj[1]) {
        dist[v] = 1;
        q.push({v, 1});
    }

    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
                continue;
            }
            if (dist[v] == -1 || dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }

    if (min_cycle == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << min_cycle << endl;
    }

    return 0;
}