#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 200001;

vector<pii> adj[MAXN];
int n, m, ans;

void dfs(int u, int dep) {
    for (auto &edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (dep + weight < ans) {
            ans = dep + weight;
            dfs(v, dep + weight);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1}); // Assuming it's an undirected graph and weight of 1
        adj[v].push_back({u, 1}); // Assuming it's an undirected graph and weight of 1
    }

    ans = INT_MAX;
    dfs(1, 0);
    if (ans == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}