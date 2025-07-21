#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
bool visited[MAXN];

int bfs(int start, int target) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == target) return dist;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }

    return INT_MAX; // If no path is found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    int result = bfs(1, n);
    if (result == INT_MAX) cout << "-1" << endl;
    else cout << result << endl;

    return 0;
}