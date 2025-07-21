#include<iostream>
#include<queue>
#include<vector>
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

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
vector<int> adj[N];
int dist[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    
    for(int start : adj[1]) {
        queue<int> q;
        fill(dist, dist + n + 1, INF);
        dist[start] = 1;
        q.push(start);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]) {
                if(v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    continue;
                }
                if(dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    if(min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main(){
    IOS;
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}