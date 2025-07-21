#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct edge {
    int to;
} a[200001]; // Assuming each edge only needs to store the destination node since the problem description hints at a single-node graph with weighted paths to all other nodes.

int n, m;
vector<int> head[200001];
int cnt, ans[200001];
bitset<200001> visited;

inline void addEdge(int u, int v) {
    head[u].push_back(v); // Using vector to handle multiple edges if needed.
}

void dfs(int u, int dep) {
    if (dep < ans[u]) {
        ans[u] = dep;
        for (int v : head[u]) {
            dfs(v, dep + 1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        ans[i] = 100000000; // Initialize distances to a large value.
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // Assuming undirected graph for simplicity.
    }
    visited.reset();
    dfs(1, 0); // Assuming 1 is the root node.
    if (ans[1] == 100000000) {
        printf("-1\n");
    } else {
        printf("%d\n", ans[1]);
    }
    return 0;
}