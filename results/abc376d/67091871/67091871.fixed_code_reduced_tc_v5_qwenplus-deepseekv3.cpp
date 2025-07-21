#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<pair<int, int>> q; // {node, distance}
    vector<int> visited(n + 1, -1); // -1 means not visited
    q.push({1, 0});
    visited[1] = 0;
    int min_cycle = -1;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int node = current.first;
        int dist = current.second;

        for (int neighbor : adj[node]) {
            if (neighbor == 1) {
                if (min_cycle == -1 || dist + 1 < min_cycle) {
                    min_cycle = dist + 1;
                }
            }
            if (visited[neighbor] == -1) {
                visited[neighbor] = dist + 1;
                q.push({neighbor, dist + 1});
            }
        }
    }

    cout << min_cycle << endl;
    return 0;
}