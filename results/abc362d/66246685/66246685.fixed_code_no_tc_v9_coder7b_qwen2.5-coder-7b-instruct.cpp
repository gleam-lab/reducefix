#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

void dijkstra(const vector<vector<P>>& g, const VL& a, int s, VL& dist) {
    int n = g.size();
    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(a[s], s);
    dist[s] = a[s];

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (dist[u] < cost) continue;
        
        for (auto [v, d] : g[u]) {
            if (dist[v] > dist[u] + d + a[v]) {
                dist[v] = dist[u] + d + a[v];
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N), B(M), ans(N - 1);
    vector<vector<pair<ll, ll>>> G(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v >> B[i];
        --u; --v;
        G[u].emplace_back(v, B[i]);
        G[v].emplace_back(u, B[i]);
    }

    for (int i = 1; i < N; ++i) {
        VL dist(N, inf);
        dijkstra(G, A, i, dist);
        ans[i - 1] = dist[0];
    }

    for (int i = 0; i < N - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}