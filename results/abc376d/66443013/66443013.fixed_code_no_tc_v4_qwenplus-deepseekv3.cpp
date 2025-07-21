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
    
    ll ans = -1;
    queue<pair<ll, ll>> q; // {current node, distance}
    vector<ll> dist(n+1, -1);
    
    // Start BFS from node 1's neighbors
    for(auto neighbor : graph[1]) {
        q.push({neighbor, 1});
        dist[neighbor] = 1;
    }
    
    while(!q.empty()) {
        auto [current, d] = q.front();
        q.pop();
        
        for(auto next : graph[current]) {
            if(next == 1) {
                if(ans == -1 || d+1 < ans) {
                    ans = d+1;
                }
                continue;
            }
            if(dist[next] == -1 || d+1 < dist[next]) {
                dist[next] = d+1;
                q.push({next, d+1});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}