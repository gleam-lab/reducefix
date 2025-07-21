#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int to;
};

vector<Edge> adj[200001];
int n, m, ans[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

void bfs() {
    queue<int> q;
    q.push(1);
    ans[1] = 0;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto e : adj[u]) {
            int v = e.to;
            if (ans[v] > ans[u] + 1) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000;
    
    for (int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        adj[u].push_back({v});
    }
    
    bfs();
    
    if (ans[n] == 100000000) 
        printf("-1");
    else 
        printf("%d", ans[n]);
}