#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
ll n, m, mn = INT_MAX;
bool vis[N];
vector<int> b[N];

void dfs(int x, int cnt) {
    vis[x] = true;
    ll ans = cnt + 1;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], ans);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Assuming the graph is undirected
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            mn = min(mn, dfs(i, -1));
        }
    }

    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }

    return 0;
}