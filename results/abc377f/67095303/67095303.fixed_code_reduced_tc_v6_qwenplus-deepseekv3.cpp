#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)(r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}


void solve() {
    int n, m;
    cin >> n >> m;
    set<int> h, v, d1, d2;
    vector<PII> pieces;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        h.insert(a);
        v.insert(b);
        d1.insert(a + b);
        d2.insert(a - b);
        pieces.emplace_back(a, b);
    }

    int total_rows = h.size();
    int total_cols = v.size();
    int total_d1 = d1.size();
    int total_d2 = d2.size();

    int safe = (n - total_rows) * (n - total_cols);

    set<int> rows_in_d1, cols_in_d1;
    for (auto d : d1) {
        int min_i = max(1LL, d - n);
        int max_i = min(n, d - 1);
        int cnt = max_i - min_i + 1;
        set<int> covered_rows;
        for (auto x : h) {
            if (d - x >= 1 && d - x <= n) {
                covered_rows.insert(x);
            }
        }
        for (auto y : v) {
            if (d - y >= 1 && d - y <= n) {
                covered_rows.insert(d - y);
            }
        }
        safe -= (cnt - covered_rows.size());
    }

    set<int> rows_in_d2, cols_in_d2;
    for (auto d : d2) {
        int min_i = max(1LL, 1 - d);
        int max_i = min(n, n - d);
        int cnt = max_i - min_i + 1;
        set<int> covered_rows;
        for (auto x : h) {
            if (x - d >= 1 && x - d <= n) {
                covered_rows.insert(x);
            }
        }
        for (auto y : v) {
            if (y + d >= 1 && y + d <= n) {
                covered_rows.insert(y + d);
            }
        }
        for (auto piece : pieces) {
            if (piece.first - piece.second == d) {
                covered_rows.insert(piece.first);
            }
        }
        safe -= (cnt - covered_rows.size());
    }

    for (auto d : d1) {
        for (auto e : d2) {
            if ((d + e) % 2 == 0 && (d - e) % 2 == 0) {
                int i = (d + e) / 2;
                int j = (d - e) / 2;
                if (i >= 1 && i <= n && j >= 1 && j <= n) {
                    if (h.count(i) == 0 && v.count(j) == 0) {
                        safe++;
                    }
                }
            }
        }
    }

    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}