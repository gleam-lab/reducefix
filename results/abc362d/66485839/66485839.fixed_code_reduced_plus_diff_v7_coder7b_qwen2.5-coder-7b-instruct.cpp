#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define trav(a, x) for(auto &a : x)

const int INF = 1e9+7;
const ll INFLL = 1e18+7;

void dijkstra(const vector<vpii>& adj, int src, vll& dist) {
    priority_queue<pll, vpll, greater<pll>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        trav(v, adj[u]) {
            int w = v.second;
            int v1 = v.first;
            
            if (dist[u] + w + dist[v1] < dist[v1]) {
                dist[v1] = dist[u] + w + dist[v1];
                pq.push({dist[v1], v1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<vpii> adj(n+1);
    vll dist(n+1, INF);
    
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    
    dijkstra(adj, 1, dist);
    
    rep(i, 2, n+1) {
        cout << min(dist[i], 1LL*INF) << " ";
    }
    
    return 0;
}