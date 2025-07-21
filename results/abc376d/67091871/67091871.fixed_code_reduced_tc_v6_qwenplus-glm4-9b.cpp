#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<int> b[200005];
vector<int> order;
vector<bool> vis;

void dfs(int x, ll cnt) {
    vis[x] = true;
    if (b[x].empty()) {
        order.push_back(cnt);
    }
    for (int i = 0; i < b[x].size(); ++i) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    vis.resize(n + 1, false);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    sort(order.begin(), order.end());
    if (order.empty()) {
        cout << -1;
    } else {
        cout << order.front();
    }
    return 0;
}