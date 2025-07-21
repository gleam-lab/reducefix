#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

struct Node {
    int x;
    i128 w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

ostream& operator<<(ostream& os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    string s;
    bool flg = n < 0;
    if (flg) {
        n = -n;
    }
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    if (flg) s += '-';
    reverse(s.begin(), s.end());
    return os << s;
}

constexpr int N = 2e5 + 10;
constexpr i128 inf = numeric_limits<i128>::max();
priority_queue<Node> pq;
vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    vector<i128> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    
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
        auto [x, w] = pq.top();
        pq.pop();
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}