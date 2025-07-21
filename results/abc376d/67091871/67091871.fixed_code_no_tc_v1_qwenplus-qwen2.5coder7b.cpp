#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200005;
ll n, m, mn = INT_MAX, vis[MAXN];
vector<int> b[MAXN];

void dfs(int x, int cnt) {
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
        int y = b[x][i];
        if (!vis[y]) {
            dfs(y, cnt + 1);
        }
    }
    if (x != 1 && !vis[x]) {
        mn = min(mn, cnt);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Assuming undirected graph
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}