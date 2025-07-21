#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int MAXN = 200005;

vector<pii> G[MAXN];
long long dis[MAXN];

void dijkstra(int n, int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dis, dis + n + 1, INF);
    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dis[u]) continue;

        for (auto &[v, w] : G[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; ++i) {
        cout << min(dis[i] + a[i], dis[i]) << " ";
    }
    cout << endl;

    return 0;
}