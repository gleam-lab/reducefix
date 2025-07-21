#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 200001;
const long long INF = 1e18;

int n, m;
long long val[N];

vector<pair<int, long long>> adj[N]; // Edge weight + vertex weight

void solve() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    vector<long long> dist(N, INF);

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (w > dist[v]) continue;

        for (auto [u, weight] : adj[v]) {
            if (w + weight < dist[u]) {
                dist[u] = w + weight;
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + val[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> val[i];

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u - 1].push_back({v - 1, b + val[v - 1]}); // Adjusting for 1-based to 0-based index.
        adj[v - 1].push_back({u - 1, b + val[u - 1]});
    }

    solve();
    return 0;
}