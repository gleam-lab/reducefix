#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

#define INF INT_MAX
#define MAX_N 200000

int N, M;
vector<long long> A(MAX_N);
vector<pair<pair<int, int>, long long>> edges;
vector<long long> dist(MAX_N);

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, weight] : edges) {
            long long newDist = d + A[v] + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        edges.push_back({{u - 1, v - 1}, b});
    }

    dijkstra(0);
    for (int i = 1; i < N; ++i) cout << dist[i] << " ";
    cout << endl;

    return 0;
}