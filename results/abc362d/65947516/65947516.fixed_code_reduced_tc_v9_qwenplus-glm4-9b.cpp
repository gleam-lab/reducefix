#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> min_weight(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({A[0], 0});
    min_weight[0] = A[0];

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (min_weight[u] < weight) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to;
            long long edge_weight = edge.weight;
            long long new_weight = weight + A[v] + edge_weight;

            if (min_weight[v] > new_weight) {
                min_weight[v] = new_weight;
                pq.push({new_weight, v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << min_weight[i] << (i < n - 1 ? " " : "");
    }

    return 0;
}