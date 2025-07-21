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
    
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    q.push({1, 1});
    dist[1] = 0;
    int min_cycle = -1;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int u = current.first;
        int parent = current.second;
        
        for (int v : adj[u]) {
            if (v == 1 && parent != 1) {
                if (min_cycle == -1 || dist[u] + 1 < min_cycle) {
                    min_cycle = dist[u] + 1;
                }
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }
    
    cout << min_cycle << endl;
    return 0;
}