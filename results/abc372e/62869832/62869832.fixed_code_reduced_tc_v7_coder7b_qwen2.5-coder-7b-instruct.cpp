#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

void dfs(int node, int parent, vector<int>& dist, vector<bool>& visited) {
    visited[node] = true;
    for(auto& child : adj[node]) {
        if(child != parent && !visited[child]) {
            dist[child] = dist[node] + 1;
            dfs(child, node, dist, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int v, k;
            cin >> v >> k;
            vector<int> dist(n+1, INT_MAX);
            vector<bool> visited(n+1, false);
            dist[v] = 0;
            dfs(v, -1, dist, visited);
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(int i=1; i<=n; i++) {
                if(dist[i] != INT_MAX) pq.push({dist[i], i});
            }
            
            while(k > 1 && !pq.empty()) {
                pq.pop();
                k--;
            }
            
            if(pq.empty()) cout << "-1\n";
            else cout << pq.top().second << "\n";
        }
    }

    return 0;
}