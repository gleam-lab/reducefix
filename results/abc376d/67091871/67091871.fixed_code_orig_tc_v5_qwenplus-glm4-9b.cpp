#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200005;
ll n, m, mn = LLONG_MAX, vis[MAXN];
vector<int> adj[MAXN];
ll depth = 200005; // possible maximum depth

void dfs(int x, ll cnt) {
    vis[x] = 1;
    if (cnt < mn) {
        mn = cnt;
    }
    for (int i = 0; i < adj[x].size(); ++i) {
        int v = adj[x][i];
        if (!vis[v]) {
            dfs(v, cnt + 1);
            if (cnt + 1 < mn) {
                mn = cnt + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    if (mn == depth) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}