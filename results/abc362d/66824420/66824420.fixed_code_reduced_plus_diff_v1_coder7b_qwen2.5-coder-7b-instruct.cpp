#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;

struct Edge {
    int u, v, w;
};

class Graph {
private:
    vector<Edge> edges;
    int V;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void dijkstra(int src) {
        vector<long long> dist(V + 1, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &edge : edges) {
                if (edge.u == u || edge.v == u) {
                    int v = (edge.u == u ? edge.v : edge.u);
                    long long newDist = d + edge.w + (v != 1 ? a[v - 1] : 0);

                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        pq.push({newDist, v});
                    }
                }
            }
        }

        for (int i = 2; i <= V; ++i) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    Graph g(n);
    for(int j = 0; j < m; ++j){
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }

    g.dijkstra(1);

    return 0;
}