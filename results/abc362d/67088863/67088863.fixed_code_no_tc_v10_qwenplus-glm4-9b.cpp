#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
typedef long long ll;

const int N = 200100;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    vector<vector<pair<int, ll>>> adj(N);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(N, numeric_limits<ll>::max());
    dist[0] = 0; // Start at vertex 1, which is index 0

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0}); // Start the priority queue with the first node

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Skip if we've seen this node with a smaller or equal distance

        for (auto [v, weight] : adj[u]) {
            ll new_dist = d + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + val[i] << " ";
    }
    cout << endl;

    return 0;
}