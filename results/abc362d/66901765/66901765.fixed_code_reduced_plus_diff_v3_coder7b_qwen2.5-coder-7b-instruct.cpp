#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = LLONG_MAX / 2;

struct Edge {
    int v, w;
};

vector<Edge> G[200005];
ll dis[200005];

void dijkstra(int n, int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    fill(dis, dis + n + 1, INF);
    dis[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [dist_u, u] = pq.top(); pq.pop();

        if (dist_u > dis[u]) continue;

        for (auto& [v, w] : G[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> dis[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}