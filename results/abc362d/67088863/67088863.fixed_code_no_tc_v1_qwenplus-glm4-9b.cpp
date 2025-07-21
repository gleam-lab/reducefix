#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (ll &i : val) cin >> i;
    
    vector<vector<pair<int, ll>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    vector<ll> dist(n, INF);
    dist[0] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        
        if (dist[v] < w) continue;
        
        for (auto [u, w_edge] : adj[v]) {
            ll new_dist = w + w_edge + val[v];
            if (new_dist < dist[u]) {
                dist[u] = new_dist;
                pq.push({dist[u], u});
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}