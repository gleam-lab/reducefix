#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())

const int MAXN = 2e5 + 7;
const LL INF = 1LL << 60;

vector<pair<int, int>> adj[MAXN];
LL dist[MAXN], a[MAXN];

void dijkstra(int start) {
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    memset(dist, 0x3f, sizeof dist); // Initialize distances to infinity
    dist[start] = 0;
    pq.push(mp(0, start));

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (cost > dist[u]) continue; // Skip outdated paths

        for (auto [v, w] : adj[u]) {
            LL new_cost = cost + w + a[v]; // Correctly add the weight of the neighbor

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push(mp(new_cost, v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }

    dijkstra(1); // Start Dijkstra's from vertex 1

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}