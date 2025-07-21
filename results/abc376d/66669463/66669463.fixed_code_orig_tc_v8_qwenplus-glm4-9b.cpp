#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int n, m, ans = INT_MAX;

void dfs(int u, int dist) {
    ans = min(ans, dist);
    for (int v : adj[u]) {
        dfs(v, dist + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's undirected
    }

    dfs(1, 0);
    if (ans == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}