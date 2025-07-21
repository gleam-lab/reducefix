#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

vector<long long> dijkstra(int start, int n, vector<vector<Edge>>& graph) {
    vector<long long> dist(n, INF);
    dist[start] = 0;
    set<pair<long long, int>> pq;
    pq.emplace(0, start);
    
    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        
        if(d > dist[u]) continue;
        
        for(auto &[v, w] : graph[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
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
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<vector<Edge>> graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    vector<long long> ans(n-1);
    for(int i = 1; i < n; ++i) {
        vector<long long> dist = dijkstra(0, n, graph);
        ans[i-1] = dist[i];
    }
    
    for(int i = 0; i < n-1; ++i) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}