#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
ll n, m, mn = INT_MAX, vis[N];
vector<int> b[N];

void dfs(int x, int cnt) {
    vis[x] = 1;
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
    }

    // Start DFS from each node to find the minimum path length
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}