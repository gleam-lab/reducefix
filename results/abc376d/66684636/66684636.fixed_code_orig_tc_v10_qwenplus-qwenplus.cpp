#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = -1;

// BFS function to find the shortest cycle starting from node 1
void bfs() {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (v == 1) {
                // A cycle is found from 1 back to 1
                if (ans == -1 || dist[u] + 1 < ans)
                    ans = dist[u] + 1;
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    bfs();
    
    cout << ans << endl;
    return 0;
}