#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

const int N = 2e5 + 5;
vector <int> g[N];
int n, m, dep[N];

int bfs(int u) {
    queue <int> q;
    q.push (u);
    dep[u] = 1;
    int max_depth = 1; // Initialize max_depth to 1 since the root is at least at depth 1
    while (!q.empty ()) {
        int v = q.front ();
        q.pop ();
        for (auto to : g[v])
            if (dep[to] == 0) { // Check if the node 'to' has not been visited
                dep[to] = dep[v] + 1;
                q.push (to);
                max_depth = max(max_depth, dep[to]); // Update max_depth if necessary
            }
    }
    return max_depth; // Return the maximum depth found
}

int main () {
    ios :: sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u); // Assuming undirected graph
    }

    cout << bfs (1) << '\n'; // Start BFS from node 1
    return 0;
}