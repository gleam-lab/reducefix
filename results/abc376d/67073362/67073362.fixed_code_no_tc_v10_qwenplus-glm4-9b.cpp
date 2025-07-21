#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
#include<bits/stdc++.h>
#define Heap_int priority_queue<int, vector<int>, greater<int>>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(x) cout << ((x) ? "YES" : "NO") << endl
#define mod(x, P) (((x) % (P) + (P)) % (P))
#define ULL unsigned long long
#define PII pair<int, int>
#define PLL pair<ULL, ULL>
#define lowbit(x) ((x) & -(x))
#define LL long long
#define pb push_back
#define gcd __gcd
#define Big __int128
#define endl "\n"
#define x first
#define y second
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7;
vector<int> a[N];
int mi = INF, g[N];
int n, m;

void dfs(int u, int deep){
    g[u]++;
    for(auto i: a[u])
    {
        if(!g[i])
            dfs(i, deep + 1);
        else
            mi = min(mi, deep);
    }
}

void solve(){
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

int main(){
    IOS;
    solve();
    return 0;
}