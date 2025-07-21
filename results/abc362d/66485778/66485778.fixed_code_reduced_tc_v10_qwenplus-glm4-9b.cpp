#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 9223372036854775807

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({A[1], 1});
    vector<long long> dist(N + 1, INF);
    dist[1] = A[1];

    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto& [v, weight] : graph[u]) {
            long long newDist = currentDist + weight + A[v];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i < N ? " " : "");
    }
    cout << endl;

    return 0;
}