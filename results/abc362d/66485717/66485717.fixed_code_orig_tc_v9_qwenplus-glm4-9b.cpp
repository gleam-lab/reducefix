#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
template <typename T>
using V = vector<T>;
#define INF 1e18

void solve() {
    int N, M;
    cin >> N >> M;
    V<LL> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    V<V<pair<int, LL>>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].PB({v, c});
        g[v].PB({u, c});
    }

    priority_queue<pair<LL, int>, V<pair<LL, int>>, greater<pair<LL, int>>> pq;
    V<LL> dist(N + 1, INF);
    dist[1] = A[1];
    pq.PB({A[1], 1});

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            LL nextDist = dist[u] + A[v] + w;
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.PB({nextDist, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i < N ? " " : "");
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}