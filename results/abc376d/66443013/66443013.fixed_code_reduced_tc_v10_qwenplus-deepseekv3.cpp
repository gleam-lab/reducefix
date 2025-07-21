#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1LL<<60;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = inf;
    queue<pair<ll, ll>> q; // {node, distance}
    vector<ll> dist(n+1, inf);
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [current, d] = q.front();
        q.pop();
        
        for (auto neighbor : graph[current]) {
            if (neighbor == 1) {
                if (d + 1 > 1) {
                    ans = min(ans, d + 1);
                }
                continue;
            }
            if (dist[neighbor] > d + 1) {
                dist[neighbor] = d + 1;
                q.push({neighbor, d + 1});
            }
        }
    }
    
    if (ans != inf) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}