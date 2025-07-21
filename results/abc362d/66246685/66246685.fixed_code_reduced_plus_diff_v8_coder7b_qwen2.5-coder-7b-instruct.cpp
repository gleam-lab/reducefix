#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vec = vector<ll>;

const ll INF = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vec A(N);
    vec dist(N, INF);
    vec seen(N, false);
    vector<vec> G(N);

    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v; // Adjust for 0-based indexing
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto cmp = [&](const pll &a, const pll &b) { return a.second > b.second; };
    set<pll, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0); // Start at node 0 with distance 0

    while (!pq.empty()) {
        auto [node, d] = *pq.begin(); pq.erase(pq.begin());

        if (seen[node]) continue;
        seen[node] = true;
        dist[node] = d;

        for (auto neighbor : G[node]) {
            if (!seen[neighbor]) {
                pq.emplace(neighbor, d + A[neighbor]);
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}