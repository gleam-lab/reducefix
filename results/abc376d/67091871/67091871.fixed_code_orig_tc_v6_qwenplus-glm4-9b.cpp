#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, mn = 0, vis[200005];
vector<int> b[200005];
void dfs(int x, int cnt) {
    if (cnt > mn) return; // Prune the search to avoid unnecessary work.
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0); // Start DFS from node 1

    // If mn is still 0, it means the graph was empty or there was no path from node 1.
    if (mn == 0) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}