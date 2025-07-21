#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>; // Changed to store path weight with vertex index

const ll inf = 1000000001;

int main() {
    ll N, M;
    cin >> N >> M;

    VL A(N), B(M);
    VL dist(N, inf), ans(N);
    vector<vector<pair<int, ll>>> G(N);

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (ll i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v >> B[i];
        u--; v--;
        G[u].push_back({v, B[i]});
        G[v].push_back({u, B[i]});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0}); // Start from vertex 1 (index 0) with 0 path weight

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;
        ans[u] = d; // Update answer for vertex u

        for (auto [v, w] : G[u]) {
            ll newDist = d + w + A[v];
            if (dist[v] > newDist) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for (ll i = 1; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}