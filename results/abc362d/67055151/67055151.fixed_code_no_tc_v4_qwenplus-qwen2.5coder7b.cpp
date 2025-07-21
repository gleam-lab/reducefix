#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};

struct Compare {
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second > b.second;
    }
};

vector<ll> dijkstra(int start, vector<vector<Edge>>& adj, vector<ll>& weight) {
    int n = adj.size();
    vector<ll> dist(n, LLONG_MAX);
    dist[start] = weight[start];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
    pq.push({start, weight[start]});
    
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        
        for (Edge& e : adj[u]) {
            int v = e.to;
            ll alt = dist[u] + e.cost + weight[v];
            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push({v, alt});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<ll> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }
    
    vector<ll> result(n - 1);
    for (int i = 1; i < n; ++i) {
        vector<ll> dist = dijkstra(0, adj, weight);
        result[i - 1] = dist[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    
    return 0;
}