#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 2 * 100000 + 1;
const int MAX_E = 2 * 100000 + 1;

vector<pii> adj[MAX_N];
int weights[MAX_N];
int dist[MAX_N];

void dijkstra(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;
    pq.push(pii(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_dist = dist[u] + weight + weights[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push(pii(new_dist, v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> weights[i];

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--; // Adjusting for 0-based indexing
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    dijkstra(0, n);

    for (int i = 1; i < n; ++i)
        cout << dist[i] << " ";

    return 0;
}