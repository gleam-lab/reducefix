#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
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
vector<int> a[N];
bool visited[N];

void dfs(int u, int depth, int& min_edges) {
    visited[u] = true;
    for(auto v : a[u]) {
        if(!visited[v]) {
            dfs(v, depth + 1, min_edges);
        } else if(v == 1 && depth > 1) { // Cycle found and it does not include itself
            min_edges = min(min_edges, depth);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }

    memset(visited, false, sizeof(visited));
    int min_edges = INF;

    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(i, 1, min_edges);
        }
    }

    if(min_edges == INF)
        cout << -1;
    else
        cout << min_edges;
}

signed main() {
    IOS;
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}