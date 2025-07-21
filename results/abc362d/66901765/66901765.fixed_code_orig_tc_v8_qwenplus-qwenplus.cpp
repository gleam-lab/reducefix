#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> G(200005); // G[u] = list of (v, B_uv)
int dis[200005];                        // Minimum path cost to reach each node
int A[200005];                         // Vertex weights
bool vis[200005];                      // Visited array

void dijkstra(int start, int N) {
    fill(dis, dis + N + 1, INF);
    dis[start] = A[start]; // Start includes weight of node 1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, b] : G[u]) {
            // d already includes A[u]
            int new_cost = d + b + A[v] - A[u]; // Subtract A[u] to avoid double count
            if (!vis[v] && new_cost < dis[v]) {
                dis[v] = new_cost;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b}); // Undirected graph
    }

    dijkstra(1, N);

    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}