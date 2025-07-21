#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> graph(200005); // graph[u] = list of {v, edge_weight}
int A[200005]; // Vertex weights
int dist[200005]; // Total distance to node
bool visited[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = A[start];
    pq.push({dist[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, w] : graph[u]) {
            if (!visited[v] && dist[v] > d + A[v] + w) {
                dist[v] = d + A[v] + w;
                pq.push({dist[v], v});
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
        dist[i] = INF;
    }

    for (int i = 1; i <= M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    dijkstra(1);

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}