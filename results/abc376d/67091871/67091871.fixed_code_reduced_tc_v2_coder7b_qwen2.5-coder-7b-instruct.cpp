#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;

int n, m, mn = INT_MAX, vis[MAXN];
vector<int> b[MAXN];

void dfs(int x, int cnt) {
    if (vis[x]) return;
    vis[x] = 1;
    int ans = cnt + 1;
    for (int v : b[x]) {
        if (!vis[v] || v == 1) {
            if (v == 1) {
                mn = min(mn, ans);
                return;
            } else {
                dfs(v, ans);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
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