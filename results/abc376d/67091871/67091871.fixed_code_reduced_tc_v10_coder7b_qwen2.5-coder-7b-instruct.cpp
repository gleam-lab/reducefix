#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 7;
ll n, m, mn = INT_MAX, vis[MAXN];
vector<int> b[MAXN];

void dfs(int x, int cnt) {
    vis[x] = 1;
    ll ans = cnt + 1;
    bool hasOne = false;
    for (auto &y : b[x]) {
        if (!vis[y] || y == 1) {
            if (y == 1) {
                hasOne = true;
            } else {
                dfs(y, ans);
            }
        }
    }
    if (hasOne) {
        mn = min(mn, ans);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Ensure undirected graph
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}