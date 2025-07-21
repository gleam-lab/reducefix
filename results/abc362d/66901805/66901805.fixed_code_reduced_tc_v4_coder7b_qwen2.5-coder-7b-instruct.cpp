#include<bits/stdc++.h>
using namespace std;

typedef __int128_t ll;

const ll INF = numeric_limits<ll>::max();

vector<vector<pair<ll, int>>> G;
vector<ll> dis;

void dij(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > dis[u]) continue;

        for (auto &[v, w] : G[u]) {
            ll new_dist = dist + w + dis[v];
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    G.resize(n + 1);
    dis.assign(n + 1, INF);

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = a[i]; // Initialize distance to vertex weight
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dij(1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";

    return 0;
}