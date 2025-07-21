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

const int N = 2e5 + 10;
int n, m;
vector<int> a[N];
int min_height = INF;
int visited[N];

void dfs(int u, int h){
    visited[u] = 1;
    min_height = min(min_height, h);
    for(int v : a[u]){
        if(!visited[v])
            dfs(v, h + 1);
    }
}

void solve(){
    for(int i = 1; i <= n; i++)
        a[i].clear();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    if(min_height == INF)
        cout << -1;
    else
        cout << min_height;
}

int main(){
    IOS;
    cin >> n >> m;
    solve();
    return 0;
}