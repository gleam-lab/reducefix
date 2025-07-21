#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9 + 7;

struct Edge {
    int to, weight;
};

vector<Edge> adj[MAXN];
long long dist[MAXN];

void dijkstra(int start, int n) {
    fill(dist, dist + n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            long long newDist = d + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjust for 0-based indexing
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    unordered_set<int> visited;
    for (int i = 1; i <= n; ++i) {
        if (visited.count(i)) continue;
        dijkstra(i - 1, n);
        visited.insert(i);
        for (int j = 1; j <= n; ++j) {
            if (dist[j - 1] != INF) {
                cout << dist[j - 1] + dist[i - 1] + dist[j - 1] << " ";
            } else {
                cout << "INF ";
            }
        }
        cout << "\n";
    }

    return 0;
}