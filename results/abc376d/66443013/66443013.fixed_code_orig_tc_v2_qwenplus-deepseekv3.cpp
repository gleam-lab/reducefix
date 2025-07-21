#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll inf=1LL<<60;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> graph(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = inf;
    
    for(ll start : graph[1]) {
        queue<pair<ll, ll>> q;
        vector<ll> dist(n+1, -1);
        q.push({start, 1});
        dist[start] = 1;
        
        while(!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            
            if(node == 1) {
                ans = min(ans, d);
                break;
            }
            
            for(ll neighbor : graph[node]) {
                if(dist[neighbor] == -1) {
                    dist[neighbor] = d + 1;
                    q.push({neighbor, d + 1});
                }
            }
        }
    }
    
    if(ans != inf) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}