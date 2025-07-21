#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using Edge = tuple<int, int, i64>;

const int MAXN = 2e5 + 10;
vector<pii> adj[MAXN]; // Adjacency list: {neighbor, edge index}
i64 A[MAXN];
i64 dist[MAXN];
bool vis[MAXN];

struct Node {
    int u;
    i64 d;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = numeric_limits<i64>::max();
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    
    priority_queue<Node> pq;
    dist[1] = A[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, eid] : adj[u]) {
            if (vis[v]) continue;
            i64 new_d = d + /* edge weight */ B[eid] + A[v];
            if (new_d < dist[v]) {
                dist[v] = new_d;
                pq.push({v, dist[v]});
            }
        }
    }
    
    for (int i = 2; i <= N; ++i)
        cout << dist[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}