#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int N = 200005;

vector<vector<pair<int, ll>>> adj(N);
vector<ll> dist(N, INF);
vector<ll> vertex_weight(N);

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> vertex_weight[i];
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        
        if (dist[v] < w) continue;
        
        for (auto [u, w_edge] : adj[v]) {
            ll new_dist = w + w_edge + vertex_weight[v];
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
    cin.tie(0);
    
    solve();
    
    return 0;
}