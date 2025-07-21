#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;

struct Edge {
    int to, cost;
    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

struct Compare {
    bool operator()(pair<int, ll> &a, pair<int, ll> &b) {
        return a.second > b.second;
    }
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start, int n) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, Compare> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        ll d = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge &e : adj[u]) {
            int v = e.to;
            ll nd = d + e.cost;

            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({v, nd});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dijkstra(0, n);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}