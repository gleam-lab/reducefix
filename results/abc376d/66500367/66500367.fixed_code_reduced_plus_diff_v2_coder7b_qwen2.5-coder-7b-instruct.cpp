#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

bool bfs() {
    queue<pii> q;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            q.push({i, 0});
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front().first, p = q.front().second;
                q.pop();

                for (auto v : g[u]) {
                    if (v == p) continue; // Skip the parent node
                    if (visited[v]) return true; // Cycle detected
                    visited[v] = true;
                    q.push({v, u});
                }
            }
        }
    }

    return false; // No cycle detected
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Add both directions since it's an undirected graph
    }

    if (bfs()) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}