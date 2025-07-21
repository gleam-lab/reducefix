#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 1e9;

int N, M;
vector<int> A;
vector<pair<int, pair<int, int>>> edges; // (weight, (from, to))

void dijkstra(int start) {
    vector<int> dists(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dists[start] = A[start - 1];
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : edges) {
            int v = edge.second.first;
            int weight = edge.second.second;

            if (dists[u] + weight < dists[v]) {
                dists[v] = dists[u] + weight;
                pq.push({dists[v], v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dists[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        edges.push_back({b, {u, v}});
    }

    dijkstra(1);

    return 0;
}