#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<pair<int, int>> G[MAXN];
int n, m;
long long dis[MAXN];

void dij(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    memset(dis, INF, sizeof(dis));
    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;

        for (auto [v, w] : G[u]) {
            long long new_d = d + a[v] + w;
            if (new_d < dis[v]) {
                dis[v] = new_d;
                pq.push({new_d, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dij(1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
}