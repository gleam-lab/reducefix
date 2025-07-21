#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
vector<pair<int, int>> G[200005];
int dis[200005];
bool vis[200005];
int A[200005];

void dijkstra(int src, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    fill(dis, dis + N + 2, INF);
    fill(vis, vis + N + 2, false);

    dis[src] = A[src];
    pq.push({dis[src], src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : G[u]) {
            if (!vis[v] && dis[v] > d + A[v] + w) {
                dis[v] = d + A[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1, N);

    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";

    return 0;
}