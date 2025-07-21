#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000LL;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> A(N), B(M), ans(N, LLONG_MAX);
    vector<vector<pair<ll, ll>>> G(N);
    vector<bool> seen(N, false);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v >> B[i];
        u--;
        v--;
        G[u].push_back(make_pair(v, B[i]));
        G[v].push_back(make_pair(u, B[i]));
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({A[0] + A[0], 0});  // Push initial position with vertex weight A[0] included twice

    while (!pq.empty()) {
        ll dist = pq.top().first;
        ll current = pq.top().second;
        pq.pop();

        if (seen[current]) continue;
        seen[current] = true;

        if (current != 0) {
            ans[current] = dist;
        }

        for (auto [neighbor, edge_weight] : G[current]) {
            if (!seen[neighbor]) {
                ll new_dist = dist + edge_weight + A[neighbor];
                pq.push({new_dist, neighbor});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}