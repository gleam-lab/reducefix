#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 200005;

std::vector<int> adj[MAXN];
int n, m, dist[MAXN];

void bfs() {
    std::fill(dist, dist + n + 1, INT_MAX);
    dist[1] = 0;
    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();

    int ans = *std::max_element(dist + 2, dist + n + 1);
    if (ans == INT_MAX) std::cout << "-1" << std::endl;
    else std::cout << ans << std::endl;

    return 0;
}