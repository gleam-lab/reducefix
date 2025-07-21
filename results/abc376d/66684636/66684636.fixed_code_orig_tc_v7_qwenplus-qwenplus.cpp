#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = -1;

// We perform BFS from node 1 and look for the shortest cycle that starts and ends at node 1.
void bfs() {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (v == 1) {
                // If we reach back to node 1, then current path length + 1 forms a cycle.
                if (ans == -1 || dist[u] + 1 < ans)
                    ans = dist[u] + 1;
                return;
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bfs();

    cout << ans << endl;
    return 0;
}