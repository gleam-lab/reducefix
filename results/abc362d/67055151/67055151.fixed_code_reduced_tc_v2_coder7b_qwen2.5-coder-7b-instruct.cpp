#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(x) cerr << (#x) << " = " << (x) << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<ll> dist(N, LLONG_MAX);
vector<bool> visited(N, false);

void dijkstra(int start, vector<ll> &weights, vector<int> &dist) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + weights[v] + w) {
                dist[v] = dist[u] + weights[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> result(n - 1, LLONG_MAX);
    dijkstra(0, weights, dist);

    for (int i = 1; i < n; ++i) {
        result[i - 1] = dist[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}