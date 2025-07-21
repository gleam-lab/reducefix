#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

struct DSU {
    vi parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1, 1) {
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void union_sets(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        rank[px] += rank[py];
    }
};

vvi adj(MAXN);
vi weights(MAXN);

void dijkstra(int start, vi &dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = weights[start];
    pq.push({dist[start], start});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for(auto &[v, w] : adj[u]) {
            if(dist[v] > dist[u] + weights[v] + w) {
                dist[v] = dist[u] + weights[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> weights[i];
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vi dist(n + 1, INF);
    dijkstra(1, dist);
    
    for(int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}