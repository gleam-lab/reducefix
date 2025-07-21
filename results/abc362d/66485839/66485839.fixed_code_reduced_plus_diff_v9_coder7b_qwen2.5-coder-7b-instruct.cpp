#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

const int N = 2e5 + 10;
const ll INF = 1e18;

struct Graph {
    vector<pl> adj[N];

    void addEdge(int u, int v, ll w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dijkstra(int src) {
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        vector<ll> dist(N, INF);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dist_u, u] = pq.top();
            pq.pop();

            if (dist_u > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                ll new_dist = dist_u + w + A[v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    Graph g;
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g.addEdge(u, v, b);
    }

    vector<ll> ans(n);
    ans[1] = 0;
    for (int i = 2; i <= n; ++i) {
        auto dist = g.dijkstra(1);
        ans[i] = dist[i];
    }

    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}