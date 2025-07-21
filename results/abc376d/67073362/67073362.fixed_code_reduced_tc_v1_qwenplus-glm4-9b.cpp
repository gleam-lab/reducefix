#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
#include <vector>
#include <algorithm>
using namespace std;

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

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
vector<int> a[N];
int mi = INF, g[N];

void dfs(int u, vector<int>& depth) {
    g[u]++;
    for (auto i : a[u]) {
        if (!g[i]) {
            dfs(i, depth);
        }
    }
}

int main() {
    IOS;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    
    vector<int> depth(n + 1);
    dfs(1, depth);
    for (int i = 2; i <= n; i++) {
        if (!g[i]) {
            mi = min(mi, depth[i]);
        }
    }
    
    if (mi == INF)
        cout << -1;
    else
        cout << mi;
    
    return 0;
}