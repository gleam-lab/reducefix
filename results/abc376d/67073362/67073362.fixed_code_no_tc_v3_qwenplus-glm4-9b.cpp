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
vector<int> a[N];
int mi = INF, g[N];

void dfs(int u, int deep){
    g[u]++;
    for(auto i: a[u])
    {
        if(!g[i])
            dfs(i, deep + 1);
        else if(i == 1)
            mi = min(mi, deep + 1);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    dfs(1, 0);
    if(mi == INF)
        cout << -1;
    else
        cout << mi;
}

signed main(){
    IOS;

    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}