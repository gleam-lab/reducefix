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
    for (int i = 0; i < n; i++) cin >> val[i];
    
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
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        
        for (auto &neigh : adj[v]) {
            int u = neigh.first;
            ll weight = neigh.second;
            if (d + weight < dist[u]) {
                dist[u] = d + weight;
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] + val[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}