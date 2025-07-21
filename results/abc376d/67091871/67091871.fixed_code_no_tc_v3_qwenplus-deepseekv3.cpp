#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<pair<int, int>> q;
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    q.push({1, -1}); // {current node, parent node}

    int min_cycle = INT_MAX;

    while(!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(v == 1 && u != parent) { // Found a cycle back to 1
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }

    if(min_cycle != INT_MAX) {
        cout << min_cycle;
    } else {
        cout << -1;
    }

    return 0;
}