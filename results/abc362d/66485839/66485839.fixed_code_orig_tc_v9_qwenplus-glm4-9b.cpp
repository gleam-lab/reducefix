#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

vector<int> adjList[200001]; // Assuming maximum node value 200000 for simplicity
int dist[200001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0LL, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto v : adjList[u]) {
            int nextDist = currentDist + dist[v];
            if (nextDist < dist[u]) {
                dist[v] = nextDist;
                pq.push({nextDist, v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int A[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        dist[u] += A[u];
        dist[v] += A[v];
    }

    dijkstra(1);

    for (int i = 2; i <= N; i++) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }

    return 0;
}