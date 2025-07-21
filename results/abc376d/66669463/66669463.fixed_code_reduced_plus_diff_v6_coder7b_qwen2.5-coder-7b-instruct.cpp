#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 200001;

struct Edge {
    int to, next;
};

vector<Edge> adj[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (Edge e : adj[u]) {
            if (!visited[e.to]) {
                visited[e.to] = true;
                ans[e.to] = min(ans[e.to], ans[u] + 1);
                q.push(e.to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, adj[u].size()});
        adj[v].push_back({u, adj[v].size()});
    }

    memset(ans, 0x3f, sizeof(ans));
    ans[1] = 0;

    bfs(1);

    if (ans[1] == INT_MAX / 2) cout << "-1" << endl;
    else cout << ans[1] << endl;

    return 0;
}