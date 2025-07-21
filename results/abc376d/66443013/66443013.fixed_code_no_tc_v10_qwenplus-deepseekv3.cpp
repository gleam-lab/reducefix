#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> graph;
    
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = -1;
    queue<pair<ll, ll>> q; // {current node, distance}
    q.push({1, 0});
    
    while(!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();
        
        for(auto neighbor : graph[current]) {
            if(neighbor == 1) {
                if(dist + 1 >= 2) { // Need at least 2 edges to form a cycle
                    if(ans == -1 || dist + 1 < ans) {
                        ans = dist + 1;
                    }
                }
                continue;
            }
            if(dist + 1 < n) { // Prevent infinite loops, longest possible simple path is n-1
                q.push({neighbor, dist + 1});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}