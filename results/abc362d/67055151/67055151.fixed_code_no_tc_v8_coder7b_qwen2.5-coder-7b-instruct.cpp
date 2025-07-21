#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int to;
    long long weight;
    Edge(int t, long long w) : to(t), weight(w) {}
};

class Graph {
private:
    int n;
    vector<vector<Edge>> adjList;
public:
    Graph(int nodes) : n(nodes), adjList(nodes) {}

    void addEdge(int u, int v, long long w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    vector<long long> dijkstra(int start) {
        vector<long long> dist(n, LLONG_MAX);
        dist[start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adjList[u]) {
                int v = edge.to;
                long long weight = edge.weight;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g.addEdge(u, v, w);
    }

    vector<long long> result(n - 1, LLONG_MAX);
    set<int> remainingNodes(n);
    for (int i = 0; i < n; ++i) {
        remainingNodes.insert(i);
    }

    auto compare = [&](const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
        return a[get<0>(x)] + get<1>(x) + get<2>(x) > a[get<0>(y)] + get<1>(y) + get<2>(y);
    };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> pq(compare);
    pq.emplace(0, 0, a[0]);

    while (!remainingNodes.empty()) {
        auto [currentNode, currentWeight, currentCost] = pq.top();
        pq.pop();

        if (!remainingNodes.count(currentNode)) continue;
        remainingNodes.erase(currentNode);
        if (currentNode != 0) {
            result[currentNode - 1] = currentCost;
        }

        for (const auto& edge : g.adjList[currentNode]) {
            int nextNode = edge.to;
            long long weight = edge.weight;
            pq.emplace(nextNode, weight, currentCost + a[nextNode] + weight);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}