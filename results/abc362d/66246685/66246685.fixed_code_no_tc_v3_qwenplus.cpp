#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].emplace_back(v, b);
        G[v].emplace_back(u, b);
    }

    vector<ll> dist(N, inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[0] = A[0];
    pq.emplace(A[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, w] : G[u]) {
            ll new_dist = dist[u] + w + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (int i = 1; i < N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}