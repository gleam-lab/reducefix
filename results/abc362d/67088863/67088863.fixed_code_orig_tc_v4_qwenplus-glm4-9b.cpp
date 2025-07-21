#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w + a[u]});
        adj[v].push_back({u, w + a[v]});
    }

    vector<int> dist(n, inf);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > dist[v]) continue;

        for (auto &e : adj[v]) {
            int to = e.first;
            int weight = w + e.second;

            if (weight < dist[to]) {
                dist[to] = weight;
                pq.push({weight, to});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}