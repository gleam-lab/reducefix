#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2 * 100005;
vector<pii> adj[MAXN];

void dijkstra(int start, int n, vector<ll>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top(); pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            ll distance = currentDist + w + dist[u];

            if (distance < dist[v]) {
                dist[v] = distance;
                pq.push({distance, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1), dist(n + 1, LLONG_MAX);
    
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> result(n);
    dijkstra(1, n, dist);

    for (int i = 2; i <= n; ++i)
        result[i] = dist[i] + a[i];

    for (int i = 2; i <= n; ++i)
        cout << result[i] << " ";

    return 0;
}