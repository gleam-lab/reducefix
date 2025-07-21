#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> graph(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = -1;
    queue<pair<ll,ll>> q;
    vector<ll> distance(n+1, -1);
    
    q.push({1, 0});
    distance[1] = 0;
    
    while(!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();
        
        for(auto neighbor : graph[current]) {
            if(neighbor == 1) {
                if(ans == -1 || dist + 1 < ans) {
                    ans = dist + 1;
                }
                continue;
            }
            if(distance[neighbor] == -1) {
                distance[neighbor] = dist + 1;
                q.push({neighbor, dist + 1});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}