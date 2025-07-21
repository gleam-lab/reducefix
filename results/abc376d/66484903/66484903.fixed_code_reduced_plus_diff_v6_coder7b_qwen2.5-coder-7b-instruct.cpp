#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
queue<int> q;
bool visited[MAXN];

int bfs(int start, int target) {
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == target) return step[u] + 1;
            if (!visited[v]) {
                step[v] = step[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return -1; // Target not reachable
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    int start = 1, target = n;
    cout << bfs(start, target) << endl;

    return 0;
}