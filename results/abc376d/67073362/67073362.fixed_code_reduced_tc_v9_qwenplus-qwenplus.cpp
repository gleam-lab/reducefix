#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // BFS from node 1
    vector<bool> visited(n+1, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    
    while(!q.empty()) {
        auto [u, dist] = q.front();
        q.pop();
        
        if(u == 1 && dist > 0) {
            cout << dist;
            return 0;
        }
        
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push({v, dist + 1});
            }
        }
    }
    
    cout << -1;
    return 0;
}