#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;

const ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N), B(M), ans(N, inf);
    vector<vector<pair<ll, ll>>> G(N);
    vector<bool> seen(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        --u; --v;
        G[u].emplace_back(v, b + A[v]);
        G[v].emplace_back(u, b + A[u]);
    }

    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(A[0], 0);

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (seen[u]) continue;
        seen[u] = true;

        for (auto [v, d] : G[u]) {
            if (seen[v]) continue;
            ans[v] = min(ans[v], cost + d);
            pq.emplace(cost + d, v);
        }
    }

    for (int i = 1; i < N; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}