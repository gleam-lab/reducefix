#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int N = 2e5 + 5;

vector<vector<pair<int, ll>>> adj(N);
vector<ll> dist(N, INF);

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (dist[v] < w) continue;

        for (auto [u, weight] : adj[v]) {
            ll new_dist = dist[v] + weight;
            if (new_dist < dist[u]) {
                dist[u] = new_dist;
                pq.push({new_dist, u});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        dist[i] = val[i];  // Initialize distances with vertex weights
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});
    }

    dijkstra(0);  // Run Dijkstra's algorithm from vertex 1

    for (int i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}