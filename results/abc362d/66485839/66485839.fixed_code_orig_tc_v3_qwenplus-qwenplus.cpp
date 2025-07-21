#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
const i64 INF = numeric_limits<i64>::max();

struct Node {
    int u;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, i64>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        i64 B;
        cin >> U >> V >> B;
        graph[U].emplace_back(V, B);
        graph[V].emplace_back(U, B);
    }

    vector<i64> dist(N + 1, INF);
    priority_queue<Node> pq;

    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, cost] : graph[u]) {
            i64 new_dist = d + cost + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}