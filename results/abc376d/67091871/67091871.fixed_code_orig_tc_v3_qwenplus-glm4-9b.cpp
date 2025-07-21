#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = LLONG_MAX, vis[200005];
vector<int> b[200005];

void dfs(int x, int cnt) {
    vis[x] = 1;
    ll ans = cnt + 1;
    for (int i = 0; i < b[x].size(); i++) {
        int v = b[x][i];
        if (!vis[v]) {
            dfs(v, ans);
        }
    }
    if (ans > 1) mn = min(mn, ans);
}

int main() {
    cin >> n >> m;

    if (m == 0) {
        // If there are no edges, the answer should be -1
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }

    dfs(1, 0);

    if (mn == LLONG_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }

    return 0;
}