#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;

struct Edge {
    int x, y, c;
    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

using i128 = __int128;
ostream& operator<<(ostream& os, i128 n) {
    // Implementation of i128 to string conversion remains the same
}

istream& operator >> (istream& is, i128& n) {
    // Implementation of i128 input remains the same
}

const int N = 2e5 + 10;
const long long INF = LLONG_MAX;
priority_queue<Edge> pq;
vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<long long> d(n + 1, INF);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    pq.emplace(1, d[1] = a[1]);
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.emplace(y, d[y]);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "" : " ");
    }
}