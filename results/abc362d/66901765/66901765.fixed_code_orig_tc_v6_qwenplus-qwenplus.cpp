#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> G(200005);
int dis[200005];
bool vis[200005];

void dijkstra(int start, const vector<int>& A) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[start] = A[start - 1]; // since nodes are 1-based in input
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : G[u]) {
            if (!vis[v] && dis[v] > d + A[v - 1] + w) {
                dis[v] = d + A[v - 1] + w;
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

    vector<int> A(N + 1); // A[0] unused
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    fill(dis + 1, dis + N + 1, INF);
    dijkstra(1, A);

    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";
}