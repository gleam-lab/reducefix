#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--; // Convert to 0-based index
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    // BFS to find the minimum weight path from vertex 1 to all other vertices
    vector<int> dist(N, INF);
    queue<int> Q;
    dist[0] = A[0];
    Q.push(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (auto& edge : G[v]) {
            int to = edge.first;
            int weight = edge.second;
            if (dist[v] + weight < dist[to]) {
                dist[to] = dist[v] + weight;
                Q.push(to);
            }
        }
    }

    // Output the minimum weights for paths from vertex 1 to all other vertices
    for (int i = 1; i < N; i++) {
        cout << dist[i] << (i < N - 1 ? " " : "");
    }

    return 0;
}