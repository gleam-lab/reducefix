#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int n, m, ans[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    ans[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (ans[v] == -1) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; ++i) ans[i] = -1;
    bfs(1);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) ans[i] = 100000000;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 100000000) cout << "-1";
        else cout << ans[i];
        if (i < n) cout << " ";
    }
    return 0;
}