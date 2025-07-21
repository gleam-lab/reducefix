#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
typedef pair<long long, int> pii;

vector<pii> G[MAXN];
long long dis[MAXN], a[MAXN];

void dijkstra(int start) {
    fill(dis, dis + MAXN, LLONG_MAX);
    dis[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > dis[u]) continue;

        for (auto [v, w] : G[u]) {
            if (dis[u] + a[v] + w < dis[v]) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].emplace_back(v, b);
        G[v].emplace_back(u, b);
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";

    return 0;
}