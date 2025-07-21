#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()

typedef long long ll;

struct Edge {
    int to, cost;
};

vector<Edge> graph[200010];
ll dist[200010];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void dijkstra(int start) {
    fill(dist, dist + 200010, LLONG_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;

        for(auto [v, c] : graph[u]) {
            if(dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, m) {
        int u, v, b; cin >> u >> v >> b;
        --u, --v;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<ll> result(n - 1);
    rep(i, n) {
        dijkstra(i);
        rep(j, n) if(i != j) result[i - 1] = max(result[i - 1], dist[j] + a[j]);
    }

    rep(i, n - 1) cout << result[i] << " ";

    return 0;
}