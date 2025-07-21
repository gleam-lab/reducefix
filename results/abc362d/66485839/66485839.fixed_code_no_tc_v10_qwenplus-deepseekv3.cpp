#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int vertex;
    ll distance;
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        ll B;
        cin >> U >> V >> B;
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    vector<ll> dist(N + 1, INF);
    priority_queue<Node> pq;
    dist[1] = A[1]; // Start at vertex 1 with its weight
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        ll d = current.distance;
        if (d > dist[u]) continue; // Skip outdated entries
        for (const Edge& e : graph[u]) {
            int v = e.to;
            ll new_dist = d + e.cost + A[v]; // Add edge cost and destination vertex weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}