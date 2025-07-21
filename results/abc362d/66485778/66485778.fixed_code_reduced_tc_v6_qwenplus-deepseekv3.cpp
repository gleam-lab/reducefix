#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int vertex;
    ll distance;
    bool operator<(const Node& other) const {
        return distance > other.distance;
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
    vector<bool> visited(N + 1, false);
    priority_queue<Node> pq;

    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        if (visited[u]) continue;
        visited[u] = true;
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            ll cost = edge.cost;
            if (dist[u] + cost + A[v] < dist[v]) {
                dist[v] = dist[u] + cost + A[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (i > 2) cout << " ";
        cout << dist[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}