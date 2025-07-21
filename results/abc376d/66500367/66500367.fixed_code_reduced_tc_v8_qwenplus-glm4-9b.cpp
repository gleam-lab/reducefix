#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

const int N = 2e5 + 5;
vector <int> g[N];
int n, m, dep[N];

int bfs () {
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (v != -1 && !dep[v]) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
    }
    return dep[1] == 0 ? -1 : dep[1];
}

int main () {
    ios :: sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(-1); // Initialize all vertices with -1 to mark them as unvisited
    }

    cout << bfs() << '\n';
    return 0;
}