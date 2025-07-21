#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;

vector<int> adj[N];
int dist[N];
int parent[N];

void bfs(int start, int n) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
        parent[i] = -1;
    }
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (v == start && parent[u] != v) {
                // Found a cycle back to the start node
                cout << dist[u] + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(1, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}