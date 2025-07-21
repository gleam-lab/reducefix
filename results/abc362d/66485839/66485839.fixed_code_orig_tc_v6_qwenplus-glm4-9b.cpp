#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int to, cost;
};

int N, M;
vector<vector<Edge>> G(N + 1);
int dist[N + 1];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if (d_u != dist[u]) continue;

        for (auto& e : G[u]) {
            int v = e.to;
            int weight = e.cost;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> dist[i];
    }

    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(1);

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i == N ? "" : " ");
    }

    return 0;
}