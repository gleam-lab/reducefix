#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int u;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

constexpr int MAXN = 2e5 + 5;

vector<vector<pii>> adj(MAXN);
i64 A[MAXN];
i64 d[MAXN];
bool vis[MAXN];

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        adj[i].clear();
        vis[i] = false;
        d[i] = numeric_limits<i64>::max();
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    priority_queue<Node> pq;
    d[1] = A[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [u, cost] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!vis[v] && d[v] > d[u] + w + A[v]) {
                d[v] = d[u] + w + A[v];
                pq.push({v, d[v]});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}