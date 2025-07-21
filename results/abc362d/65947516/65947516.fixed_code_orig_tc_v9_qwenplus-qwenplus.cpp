#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    vector<vector<pli>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        G[u].push_back({b, v});
        G[v].push_back({b, u});
    }

    vector<ll> dist(N + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[1] = A[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [b, v] : G[u]) {
            if (dist[v] > dist[u] + b + A[v]) {
                dist[v] = dist[u] + b + A[v];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}