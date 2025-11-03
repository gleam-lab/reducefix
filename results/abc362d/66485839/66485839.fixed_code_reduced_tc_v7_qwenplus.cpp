#include <bits/stdc++.h>
using namespace std;

#define INT signed
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct Node {
    int x;
    long long w;
    bool operator < (const Node& u) const {
        return w > u.w; // Min-heap: smaller weight has higher priority
    }
};

constexpr int MAX_N = 200000 + 10;
const long long INF = numeric_limits<long long>::max();

priority_queue<Node> pq;
vector<pair<int, int>> g[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    V<long long> a(n + 1);
    V<long long> d(n + 1, INF);
    V<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    // Dijkstra from vertex 1
    d[1] = a[1]; // Starting at vertex 1, we pay its vertex weight
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (const auto& [y, edge_weight] : g[x]) {
            long long new_cost = d[x] + edge_weight + a[y];
            if (new_cost < d[y]) {
                d[y] = new_cost;
                pq.push({y, d[y]});
            }
        }
    }

    // Output distances for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i < n) cout << ' ';
        else cout << '\n';
    }
}

INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}