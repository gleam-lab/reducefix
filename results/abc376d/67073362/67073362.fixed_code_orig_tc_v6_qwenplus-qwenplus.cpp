#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int depth[N];
bool visited[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    depth[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
            // If we revisit node 1, we found a cycle back to start
            else if (v == 1) {
                cout << depth[u] + 1;
                return;
            }
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}