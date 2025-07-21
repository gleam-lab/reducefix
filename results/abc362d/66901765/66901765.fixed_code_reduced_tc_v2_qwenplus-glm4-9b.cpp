#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

vector<pair<int, int>> G[200005];
int dist[200005], vertex_weights[200005];
int n, m;

void dijkstra(int start_vertex) {
    using pair_type = pair<int, int>;
    priority_queue<pair_type, vector<pair_type>, greater<pair_type>> pq;

    pq.push({0, start_vertex});
    dist[start_vertex] = vertex_weights[start_vertex];

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) continue;

        for (auto &edge : G[current_vertex]) {
            int next_vertex = edge.first;
            int edge_weight = edge.second;

            int candidate_dist = dist[current_vertex] + vertex_weights[next_vertex] + edge_weight;

            if (candidate_dist < dist[next_vertex]) {
                dist[next_vertex] = candidate_dist;
                pq.push({dist[next_vertex], next_vertex});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &vertex_weights[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            printf("-1 ");
        } else {
            printf("%lld ", dist[i]);
        }
    }

    return 0;
}