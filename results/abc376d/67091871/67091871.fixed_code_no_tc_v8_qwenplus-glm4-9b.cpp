#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005;
vector<int> b[200005];
int vis[200005];

void dfs(int x, int cnt) {
    vis[x] = 1;
    if (cnt > mn) return;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0);
    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}