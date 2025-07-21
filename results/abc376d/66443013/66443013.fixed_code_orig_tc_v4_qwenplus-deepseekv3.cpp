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
    
    // Check direct edges from 1 back to 1
    for(auto neighbor : graph[1]) {
        if(neighbor == 1) {
            ans = 1;
            break;
        }
    }
    if(ans == 1) {
        cout << 1 << endl;
        return 0;
    }

    // For other neighbors of 1, perform BFS to find shortest path back to 1
    for(auto neighbor : graph[1]) {
        queue<pair<ll, ll>> q; // {node, distance}
        vector<ll> dist(n+1, -1);
        q.push({neighbor, 1});
        dist[neighbor] = 1;
        
        while(!q.empty()) {
            auto [current, d] = q.front();
            q.pop();
            
            if(current == 1) {
                ans = min(ans, d + 1);
                break;
            }
            
            for(auto next : graph[current]) {
                if(dist[next] == -1) {
                    dist[next] = d + 1;
                    q.push({next, d + 1});
                }
            }
        }
    }

    if(ans != LLONG_MAX) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}