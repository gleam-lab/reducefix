#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bitset>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int dist[MAXN];
bool visited[MAXN];

void bfs(int start) {
    fill(dist, dist + MAXN, INT_MAX);
    fill(visited, visited + MAXN, false);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    bool hasPath = false;
    for (int i = 2; i <= n; ++i) {
        if (dist[i] != INT_MAX) {
            hasPath = true;
            break;
        }
    }

    if (!hasPath) {
        cout << "-1" << endl;
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 2; i <= n; ++i) {
        if (dist[i] != INT_MAX) {
            ans = min(ans, dist[i]);
        }
    }

    cout << ans << endl;
    return 0;
}