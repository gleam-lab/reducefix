#include <bits/stdc++.h>
using namespace std;

struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        int root = x;
        while (root != fa[root]) {
            root = fa[root];
        }
        while (x != root) {
            int nex = fa[x];
            fa[x] = fa[fa[x]];
            x = nex;
        }
        return root;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int x, y, c;
    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

using i128 = __int128;
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
istream& operator >> (istream& is, i128& n) {
    string s;
    is >> s;
    try {
        n = 0;
        bool flg = false;
        size_t start = 0;
        if (s[0] == '-') {
            flg = true;
            start = 1;
        }
        for (size_t i = start; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                throw invalid_argument("Invalid character in input");
            }
            n = n * 10 + (s[i] - '0');
        }
        if (flg) {
            n = -n;
        }
    } catch (const invalid_argument& e) {
        is.setstate(ios::failbit);
        cerr << "Input error: " << e.what() << endl;
    }
    return is;
}

constexpr int N = 2e5 + 10;
constexpr i128 inf = 5e18;
priority_queue<pair<i128, int>, vector<pair<i128, int>>, greater<>> pq;
vector<pair<int, int>> g[N];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
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
    pq.emplace(a[1], 1);
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (const auto& [v, cw] : g[u]) {
            if (d[v] > w + a[v] + cw) {
                d[v] = w + a[v] + cw;
                pq.emplace(d[v], v);
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}