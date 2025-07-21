#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tpl;

const int MAXN = 200005;

vector<pll> adj[MAXN];
ll dist[MAXN];

void dijkstra(int src) {
    priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
    fill(dist, dist + MAXN, LLONG_MAX);
    dist[src] = 0;
    pq.push({dist[src], src, 0});
    
    while (!pq.empty()) {
        auto [d, u, w] = pq.top();
        pq.pop();
        
        if (d != dist[u]) continue;
        
        for (auto &[v, vw] : adj[u]) {
            if (dist[v] > dist[u] + w + vw + A[v]) {
                dist[v] = dist[u] + w + vw + A[v];
                pq.push({dist[v], v, w + vw});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    
    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}