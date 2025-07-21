#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> graph(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = -1;
    queue<pair<ll, ll>> q;
    vector<ll> dist(n+1, -1);
    
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [node, d] = q.front();
        q.pop();
        
        for (auto neighbor : graph[node]) {
            if (neighbor == 1) {
                if (d + 1 >= 1) {
                    if (ans == -1 || d + 1 < ans) {
                        ans = d + 1;
                    }
                }
                continue;
            }
            if (dist[neighbor] == -1) {
                dist[neighbor] = d + 1;
                q.push({neighbor, d + 1});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}