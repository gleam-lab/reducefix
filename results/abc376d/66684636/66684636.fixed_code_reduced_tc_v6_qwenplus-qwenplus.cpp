#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

// BFS is more suitable for shortest cycle detection
int bfs(int start) {
    vector<int> dist(N, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } 
            // If it's already visited and it's not the parent node,
            // then we found a cycle
            else if (v != 1 && dist[v] != dist[u] - 1) {
                return dist[u] + dist[v] + 1;
            }
        }
    }
    return -1; // No cycle found
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Undirected graph
    }

    // We want to find the shortest cycle that includes node 1
    ans = bfs(1);

    cout << ans << endl;
    return 0;
}