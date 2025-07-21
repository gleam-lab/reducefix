#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005, vis[200005];
vector<int> b[200005];

void dfs(int x, int cnt, ll &ans) {
    vis[x] = 1;
    ans = max(ans, cnt + 1);
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1, ans);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Ensure bidirectional edges for an undirected graph
    }
    ll ans = 0;
    dfs(1, 0, ans);
    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn << " " << ans;
    }
    return 0;
}