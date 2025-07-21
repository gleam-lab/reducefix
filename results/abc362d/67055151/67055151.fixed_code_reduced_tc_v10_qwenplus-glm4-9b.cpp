#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int U, V, B;
        cin >> U >> V >> B;
        adj[U - 1].push_back({V - 1, B});
        adj[V - 1].push_back({U - 1, B});
    }

    // Initialize distances with INF
    vector<int> dist(N, INF);
    dist[0] = A[0];  // Distance from vertex 1 to itself

    // Priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto& edge : adj[current]) {
            int next = edge.first;
            int weight = edge.second;

            int newDist = currentDist + A[next] + weight;

            if (newDist < dist[next]) {
                dist[next] = newDist;
                pq.push({dist[next], next});
            }
        }
    }

    // Output the minimum distances from vertex 1 to all other vertices
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}