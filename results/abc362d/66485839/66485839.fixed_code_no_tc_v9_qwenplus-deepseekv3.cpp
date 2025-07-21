#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Edge {
    int to;
    ll weight;
};

struct Node {
    int vertex;
    ll distance;
    bool operator>(const Node& other) const {
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
    dist[1] = A[1];
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        ll current_dist = current.distance;
        if (current_dist > dist[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            ll new_dist = current_dist + edge.weight + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i];
        if (i < N) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}