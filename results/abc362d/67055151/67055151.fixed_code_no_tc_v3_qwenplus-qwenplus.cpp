#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    ll to, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(N, INF);
    dist[0] = A[0];  // Start from node 0 with its weight

    auto cmp = [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
    pq.push({0, dist[0]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& e : graph[u]) {
            ll v = e.to;
            ll new_dist = dist[u] + e.cost + A[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}