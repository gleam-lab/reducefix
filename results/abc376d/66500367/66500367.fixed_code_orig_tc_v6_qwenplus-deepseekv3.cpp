#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;
int parent[N];
int dist[N];
int min_cycle = INT_MAX;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (v == parent[u]) continue;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else {
                min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
            }
        }
    }
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
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        fill(dist, dist + n + 1, -1);
        fill(parent, parent + n + 1, -1);
        bfs(i);
    }

    if (min_cycle == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << min_cycle << '\n';
    }

    return 0;
}