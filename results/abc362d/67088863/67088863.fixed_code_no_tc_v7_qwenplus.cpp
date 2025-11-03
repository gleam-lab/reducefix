#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for(ll& i : val) cin >> i;
    
    vector<vector<pair<int, ll>>> adj(n);

    for(int i = 0; i < m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<ll> dist(n, INF);
    dist[0] = val[0]; // Include starting vertex weight
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[0], 0});

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        
        if (d != dist[v]) continue; // Skip outdated entries

        for(auto [u, w] : adj[v]){
            ll new_dist = dist[v] + w + val[u]; // Add edge weight and destination vertex weight
            if (new_dist < dist[u]) {
                dist[u] = new_dist;
                pq.push({dist[u], u});
            }
        }
    }

    for(int i = 1; i < n; i++) {
        cout << dist[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}