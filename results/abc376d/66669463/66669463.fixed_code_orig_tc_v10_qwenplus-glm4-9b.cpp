#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 200001;
vector<int> graph[MAX_N];
int n, m, head[MAX_N], cnt, ans[MAX_N];

void add(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u, int dep) {
    if (u == 1 && dep > ans[1]) {
        ans[1] = dep;
    }
    for (int v : graph[u]) {
        if (dep + 1 > ans[v]) ans[v] = dep + 1;
        dfs(v, dep + 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) ans[i] = 0;
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    dfs(1, 0);
    if (ans[1] == 0) printf("-1\n");
    else printf("%d\n", ans[1]);
    return 0;
}