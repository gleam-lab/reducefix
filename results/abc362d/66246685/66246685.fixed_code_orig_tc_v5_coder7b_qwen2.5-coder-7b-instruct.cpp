#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VL = vector<LL>;
using P = pair<int, int>;

const LL inf = 1e18;

struct Edge {
    int v, w;
};

void dijkstra(const vector<VL>& adj, const vector<VL>& cost, int start, VL& dist) {
    int n = adj.size();
    dist.assign(n, inf);
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<LL> A(N);
    vector<VL> G(N), C(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) {
        int u, v;
        LL b;
        cin >> u >> v >> b;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u].push_back(b);
        C[v].push_back(b);
    }
    
    vector<LL> ans(N, inf);
    ans[0] = A[0];
    dijkstra(G, C, 0, ans);
    
    for (int i = 1; i < N; ++i) {
        cout << ans[i] + A[i] << " ";
    }
    cout << endl;
    
    return 0;
}