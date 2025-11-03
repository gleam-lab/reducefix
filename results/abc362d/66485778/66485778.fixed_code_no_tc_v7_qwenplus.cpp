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

constexpr long long inf = 1e18;
priority_queue<Node> pq;
vector<pair<int, int>> g[200010]; // Adjusted size to fit constraints

void solve2() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    vector<long long> d(n + 1, inf);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    // Initialize distance for vertex 1 with its own vertex weight
    d[1] = a[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (const auto& [y, edge_weight] : g[x]) {
            long long new_dist = d[x] + edge_weight + a[y];
            if (new_dist < d[y]) {
                d[y] = new_dist;
                pq.push({y, d[y]});
            }
        }
    }

    // Output results for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i < n) cout << ' ';
        else cout << '\n';
    }
}

INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve2();
    return 0;
}