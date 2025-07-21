#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;
constexpr long long inf = 1e18;

struct Node {
    int x, w;
    bool operator < (const Node& u) const {
        return w == u.w ? x < u.x : w > u.w;
    }
};

vector<pair<int, int>> g[N];

void dijkstra(int n, int src) {
    priority_queue<Node> pq;
    vector<long long> d(n + 1, inf);
    vector<bool> vis(n + 1, false);

    pq.emplace(src, d[src] = 0);
    
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (auto [y, dw] : g[x]) {
            if (w + dw < d[y]) {
                d[y] = w + dw;
                pq.emplace(y, d[y]);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    dijkstra(n, 1);

    return 0;
}