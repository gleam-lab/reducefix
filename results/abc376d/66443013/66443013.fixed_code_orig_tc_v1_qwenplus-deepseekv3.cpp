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
    
    const ll inf = 1LL << 60;
    ll ans = inf;
    
    vector<ll> dist(n+1, inf);
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        
        for(ll v : graph[u]) {
            if(v == 1) {
                ans = min(ans, dist[u] + 1);
            }
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if(ans != inf) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}