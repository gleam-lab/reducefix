#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define vvi vector<vector<int>>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define MAXN 400005
#define INF LLONG_MAX

vvi g[MAXN];
vector<pair<int,int>> bombs;

void dfs(int u,int p){
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u);
            bombs.pb(mp(u,v));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1;i<=n*m;i++){
        g[i].pb(i+m);
        g[i].pb(i-1);
        g[i].pb(i-m);
        g[i].pb(i+1);
    }

    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        int id = (x-1)*m+y;
        g[id].clear();
    }

    for(int i=1;i<=n*m;i++){
        if(g[i].sz() == 1){
            dfs(i,i);
            break;
        }
    }

    cout << bombs.sz()-k << '\n';

    return 0;
}