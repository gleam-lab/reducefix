#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    for (auto &[a, b] : queens) {
        cin >> a >> b;
    }

    set<ll> rows, cols, diag1, diag2;
    for (auto &[a, b] : queens) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total_squares = n * n;
    ll attacked_by_rows = rows.size() * n;
    ll attacked_by_cols = cols.size() * n;
    ll attacked_by_rows_and_cols = rows.size() * cols.size();

    ll attacked_by_diag1 = 0;
    for (auto d : diag1) {
        ll lower = max(1LL, 1 - d);
        ll upper = min(n, n - d);
        attacked_by_diag1 += upper - lower + 1;
    }

    ll attacked_by_diag2 = 0;
    for (auto d : diag2) {
        ll lower = max(1LL, d - n);
        ll upper = min(n, d - 1);
        attacked_by_diag2 += upper - lower + 1;
    }

    ll overlap_rows_diag1 = 0;
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                overlap_rows_diag1++;
            }
        }
    }

    ll overlap_cols_diag1 = 0;
    for (auto d : diag1) {
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                overlap_cols_diag1++;
            }
        }
    }

    ll overlap_rows_diag2 = 0;
    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                overlap_rows_diag2++;
            }
        }
    }

    ll overlap_cols_diag2 = 0;
    for (auto d : diag2) {
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                overlap_cols_diag2++;
            }
        }
    }

    ll overlap_diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && 1 <= a && a <= n && 1 <= b && b <= n) {
                overlap_diag1_diag2++;
            }
        }
    }

    ll overlap_rows_cols_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c)) {
                overlap_rows_cols_diag1++;
            }
        }
    }

    ll overlap_rows_cols_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r + c)) {
                overlap_rows_cols_diag2++;
            }
        }
    }

    ll safe_squares = total_squares - attacked_by_rows - attacked_by_cols + attacked_by_rows_and_cols - attacked_by_diag1 - attacked_by_diag2 + overlap_rows_diag1 + overlap_cols_diag1 + overlap_rows_diag2 + overlap_cols_diag2 + overlap_diag1_diag2 - overlap_rows_cols_diag1 - overlap_rows_cols_diag2;
    cout << safe_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}