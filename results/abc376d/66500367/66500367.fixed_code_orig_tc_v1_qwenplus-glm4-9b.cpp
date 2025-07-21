#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;
int dep[N]; // depth array should be initialized to 0 or -1, since it's not initialized in the original code

int bfs() {
    queue<int> q;
    q.push(1); // start BFS from node 1
    dep[1] = 0; // node 1 is the root, its depth is 0
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dep[v] == -1) { // if v has not been visited
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > max_depth) {
            max_depth = dep[i];
        }
    }
    return max_depth; // return the maximum depth found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // since the graph is undirected
    }

    cout << bfs() << '\n';
    return 0;
}