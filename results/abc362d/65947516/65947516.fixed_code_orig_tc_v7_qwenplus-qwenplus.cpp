#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 2e5 + 5;
int n, m;
ll a[N];
vector<pli> g[N];
ll dis[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; ++i)
        dis[i] = LLONG_MAX;
    
    dis[1] = a[1]; // Start path with A_1 included
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;
        for (auto &[v, w_edge] : g[u]) {
            ll new_cost = d + w_edge + a[v]; // Include A_v when moving to v
            if (new_cost < dis[v]) {
                dis[v] = new_cost;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i)
        cout << dis[i] << " ";
    cout << '\n';

    return 0;
}