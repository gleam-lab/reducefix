#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
vector<pair<int, int>> adj[N]; // adj[i] will store pairs of (neighbor, weight of edge)

int Parent[N];
int Size[N];

void Initialize() {
    for (int i = 0; i < N; ++i) {
        Parent[i] = i;
        Size[i] = 1;
    }
}

int Find(int u) {
    if (Parent[u] == u) return u;
    Parent[u] = Find(Parent[u]);
    return Parent[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        if (Size[u] < Size[v]) swap(u, v);
        Parent[v] = u;
        Size[u] += Size[v];
    }
}

void solve() {
    cin >> N >> M;
    Initialize();

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        Union(u, v);
    }

    vector<long long> dist(N + 1, 1e18); // Using 1e18 to handle large numbers
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            long long new_dist = current_dist + weight + adj[u][Find(u)].second;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << (i < N ? ' ' : '\n');
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    solve();
    return 0;
}