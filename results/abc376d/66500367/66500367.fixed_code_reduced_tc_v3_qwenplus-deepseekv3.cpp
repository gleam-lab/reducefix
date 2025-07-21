#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, color[N];

int bfs() {
    queue<pii> q;
    q.push({1, 1});
    color[1] = 1;
    while (!q.empty()) {
        int u = q.front().first, c = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == 0) {
                color[v] = 3 - c; // Alternate color between 1 and 2
                q.push({v, color[v]});
            } else if (color[v] == c) {
                return (color[u] + color[v] - 1) / 2; // Not the correct way to find odd-length cycle
            }
        }
    }
    return -1;
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
        g[v].push_back(u); // Ensure undirected graph
    }

    cout << bfs() << '\n';
    return 0;
}