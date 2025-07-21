#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
ll n, m, mn = INT_MAX, vis[MAXN];
vector<int> b[MAXN];

void dfs(int x, int cnt) {
    if (vis[x]) return; // Avoid revisiting nodes
    vis[x] = 1;
    ll ans = cnt + 1;
    for (int i = 0; i < b[x].size(); ++i) {
        if (!vis[b[x][i]]) { // Only visit unvisited neighbors
            dfs(b[x][i], ans);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}