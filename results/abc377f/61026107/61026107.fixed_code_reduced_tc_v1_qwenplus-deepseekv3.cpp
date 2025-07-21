#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll attacked_rows = rows.size() * N;
    ll attacked_cols = cols.size() * N;
    ll attacked_diag1 = 0;
    for (ll v : diag1) {
        if (v >= 0) {
            attacked_diag1 += N - v;
        } else {
            attacked_diag1 += N + v;
        }
    }
    ll attacked_diag2 = 0;
    for (ll v : diag2) {
        ll min_xy = max(1LL, v - N);
        ll max_xy = min(N, v - 1);
        attacked_diag2 += max_xy - min_xy + 1;
    }

    total -= attacked_rows + attacked_cols + attacked_diag1 + attacked_diag2;

    // Inclusion-exclusion for intersections
    // Row and column
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c) || diag2.count(r + c)) {
                total += 1;
            }
        }
    }

    // Row and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                total += 1;
                if (cols.count(c) || diag2.count(r + c)) {
                    total -= 1;
                }
            }
        }
    }

    // Row and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                total += 1;
                if (cols.count(c) || diag1.count(r - c)) {
                    total -= 1;
                }
            }
        }
    }

    // Column and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                total += 1;
                if (rows.count(r) || diag2.count(r + c)) {
                    total -= 1;
                }
            }
        }
    }

    // Column and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                total += 1;
                if (rows.count(r) || diag1.count(r - c)) {
                    total -= 1;
                }
            }
        }
    }

    // Diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                total += 1;
                if (rows.count(r) || cols.count(c)) {
                    total -= 1;
                }
            }
        }
    }

    // Triple intersections
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                total -= 1;
            }
        }
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    solve();
    return 0;
}