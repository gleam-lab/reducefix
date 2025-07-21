#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int MAX_N = 200010;
vector<pair<int, ll>> graph[MAX_N]; // adjacency list with weights
ll vertex_weights[MAX_N];         // vertex weights
ll min_path_weights[MAX_N];       // minimum path weights from vertex 1

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start}); // {distance, vertex}
    fill(min_path_weights + 1, min_path_weights + MAX_N, numeric_limits<ll>::max());

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > min_path_weights[u]) continue;
        for (auto [v, weight] : graph[u]) {
            ll new_dist = dist + weight + vertex_weights[v];
            if (new_dist < min_path_weights[v]) {
                min_path_weights[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << min_path_weights[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}