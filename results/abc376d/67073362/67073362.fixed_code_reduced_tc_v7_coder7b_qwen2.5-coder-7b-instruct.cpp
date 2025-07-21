#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
vector<int> a[N];
int mi = INF, g[N];

void dfs(int u, int deep) {
    g[u] = deep + 1;
    for(auto i : a[u]) {
        if(g[i] == 0)
            dfs(i, deep + 1);
        else if(i != 1)
            mi = min(mi, deep + 1);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    memset(g, 0, sizeof(g));
    dfs(1, 0);
    if(mi == INF)
        cout << -1;
    else
        cout << mi;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}