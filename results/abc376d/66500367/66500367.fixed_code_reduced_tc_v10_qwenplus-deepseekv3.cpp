#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;

int bfs(int start) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int min_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v && parent[v] != u) {
                min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
            }
        }
    }
    return min_cycle == INT_MAX ? -1 : min_cycle;
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

    int result = -1;
    for (int i = 1; i <= n; i++) {
        int current = bfs(i);
        if (current != -1) {
            if (result == -1 || current < result) {
                result = current;
            }
        }
    }

    cout << result << '\n';
    return 0;
}