#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    long long weight; // Use long long to avoid overflow
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> vertex_weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> min_weight(n + 1, LLONG_MAX); // Use LLONG_MAX for the initial weights
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    min_weight[1] = vertex_weights[1];
    pq.push({1, min_weight[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        long long w = current.weight;

        if (w > min_weight[u]) continue;

        for (Edge &edge : graph[u]) {
            int v = edge.to;
            long long next_weight = w + edge.weight;

            if (next_weight < min_weight[v]) {
                min_weight[v] = next_weight;
                pq.push({v, min_weight[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << min_weight[i] << " ";
    }
    cout << endl;

    return 0;
}