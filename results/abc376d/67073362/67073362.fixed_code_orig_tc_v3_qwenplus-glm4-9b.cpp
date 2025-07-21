#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
//~FZY.//
#include<bits/stdc++.h>
#define Heap_int priority_queue<int, vector<int>, greater<int>>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(x) cout << ((x) ? "YES" : "NO") << endl
#define mod(x, P) (((x) % (P) + (P)) % (P))
#define ULL unsigned long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define lowbit(x) ((x) & -(x))
#define LL long long
#define pb push_back
#define gcd __gcd
#define Big __int128
#define endl "\n"
#define x first
#define y second
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
vector<int> adj[N];
int visited[N], height[N], max_height = -INF;

void dfs(int u, int parent, int h) {
    visited[u] = 1;
    height[u] = h;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u, h + 1);
            max_height = max(max_height, height[v]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, 0, sizeof(visited));
    memset(height, 0, sizeof(height));
    max_height = 0;
    dfs(1, 0, 0);

    if (max_height == 0) {
        cout << -1 << endl;
    } else {
        cout << max_height << endl;
    }
}

signed main() {
    IOS;

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}