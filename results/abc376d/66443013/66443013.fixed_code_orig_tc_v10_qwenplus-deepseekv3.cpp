#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> graph(n+1);
    for(int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = LLONG_MAX;
    
    for(ll neighbor : graph[1]) {
        queue<ll> q;
        vector<ll> dist(n+1, -1);
        dist[neighbor] = 1;
        q.push(neighbor);
        
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
            
            for(ll v : graph[u]) {
                if(v == 1) {
                    ans = min(ans, dist[u] + 1);
                    continue;
                }
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    if(ans != LLONG_MAX) cout << ans << endl;
    else cout << -1 << endl;
}