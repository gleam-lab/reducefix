#include <bits/stdc++.h>

#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
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
        adj[v].push_back(u); // Since it is an undirected graph
    }

    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    bfs(1); // Start BFS from node 1

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == -1) {
            cout << "-1" << endl;
            return 0;
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}