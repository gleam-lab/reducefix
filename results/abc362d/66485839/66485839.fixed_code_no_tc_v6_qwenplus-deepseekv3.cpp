#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        return w > u.w; // For min-heap, we use greater than
    }
};

constexpr int N = 2e5 + 10;
constexpr long long inf = 1e18;
vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    V<long long> d(n + 1, inf);
    V<bool> vis(n + 1, false);
    priority_queue<Node> pq;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    pq.push({1, d[1] = a[1]});
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int x = node.x;
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.push({y, d[y]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "\n" : " ");
    }
}

INT main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}