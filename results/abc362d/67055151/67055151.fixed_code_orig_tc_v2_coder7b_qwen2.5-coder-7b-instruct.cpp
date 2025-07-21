#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int to;
    ll cost;
    Edge(int to, ll cost) : to(to), cost(cost) {}
};

struct Node {
    ll dist;
    vector<Edge> edges;
    Node() : dist(LLONG_MAX) {}
};

vector<Node> nodes;

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({nodes[start].dist, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > nodes[u].dist) continue;

        for (auto &[v, c] : nodes[u].edges) {
            ll nd = d + c + nodes[v].dist;
            if (nd < nodes[v].dist) {
                nodes[v].dist = nd;
                pq.push({nd, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    nodes.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].dist;
    }

    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        --u, --v;
        nodes[u].edges.emplace_back(v, w);
        nodes[v].edges.emplace_back(u, w);
    }

    dijkstra(0);

    for (int i = 1; i < n; ++i) {
        cout << nodes[i].dist << " ";
    }
    cout << endl;

    return 0;
}