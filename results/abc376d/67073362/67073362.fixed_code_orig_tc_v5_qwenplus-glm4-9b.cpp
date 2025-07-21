#include<iostream>
#include<queue>
#include<cstring>
#include<limits>
#define Heap_int priority_queue<int, vector<int>, greater<int>>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(x) cout << ((x) ? "YES" : "NO") << endl
#define mod(x, P) (((x) % (P) + (P)) % (P))
#define ULL unsigned long long
#define PII pair<int, int>
#define LL long long
#define pb push_back
#define gcd __gcd
#define Big __int128
#define endl "\n"
#define x first
#define y second
using namespace std;

const int N = 2e5 + 10;
vector<int> a[N];
int visited[N], depth[N];

void dfs(int u, int d) {
    visited[u] = 1;
    depth[u] = d;
    for (auto i : a[u]) {
        if (!visited[i]) {
            dfs(i, d + 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    int min_depth = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++) {
        min_depth = min(min_depth, depth[i]);
    }
    if (min_depth == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << min_depth << endl;
    }
}

int main() {
    IOS;
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}