#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m;
int dep[N] = {0}; // Initialize dep with zeros

void bfs() {
    queue<int> q;
    q.push(1);
    dep[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dep[v] == 0) { // If v has not been visited
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Assuming undirected graph
    }

    bfs();

    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        max_depth = max(max_depth, dep[i]);
    }

    cout << max_depth << '\n';
    return 0;
}