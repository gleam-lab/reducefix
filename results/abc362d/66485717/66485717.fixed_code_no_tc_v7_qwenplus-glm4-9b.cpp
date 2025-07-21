#include <bits/stdc++.h>
using namespace std;

#define INT signed
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;

struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    bool merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (sz[rootX] < sz[rootY]) swap(rootX, rootY);
            fa[rootY] = rootX;
            sz[rootX] += sz[rootY];
            return true;
        }
        return false;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int to, cost;
    bool operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

void dijkstra(const VV<Edge>& graph, const V<int>& weights, V<int>& dist) {
    int n = weights.size();
    V<int> parent(n, -1);
    dist.assign(n, 1e18);
    priority_queue<Edge, V<Edge>, greater<Edge>> pq;

    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int cur = pq.top().to;
        int curDist = pq.top().cost;
        pq.pop();
        if (curDist > dist[cur]) continue;

        for (const Edge& edge : graph[cur]) {
            int next = edge.to;
            int nextDist = curDist + edge.cost + weights[next];
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                parent[next] = cur;
                pq.push({next, nextDist});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << dist[i] << " ";
        } else {
            cout << -1 << " "; // For vertices unreachable from vertex 1
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    V<int> weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    VV<Edge> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    V<int> dist(n + 1);
    dijkstra(graph, weights, dist);

    return 0;
}