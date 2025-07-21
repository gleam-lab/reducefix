#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total = N * N;
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;

    ll diag1_attacks = 0;
    for (ll d : diag1) {
        // i - j = d
        // i ranges from max(1, 1 + d) to min(N, N + d)
        // j = i - d
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        diag1_attacks += (i_max - i_min + 1);
    }

    ll diag2_attacks = 0;
    for (ll s : diag2) {
        // i + j = s
        // i ranges from max(1, s - N) to min(N, s - 1)
        // j = s - i
        ll i_min = max(1LL, s - N);
        ll i_max = min(N, s - 1);
        if (i_min > i_max) continue;
        diag2_attacks += (i_max - i_min + 1);
    }

    total -= row_attacks + col_attacks + diag1_attacks + diag2_attacks;

    // Add back intersections
    // Rows and columns
    total += rows.size() * cols.size();

    // Rows and diag1
    for (ll a : rows) {
        for (ll d : diag1) {
            ll j = a - d;
            if (j >= 1 && j <= N) {
                if (cols.count(j)) continue; // Avoid triple counting
                total++;
            }
        }
    }

    // Rows and diag2
    for (ll a : rows) {
        for (ll s : diag2) {
            ll j = s - a;
            if (j >= 1 && j <= N) {
                if (cols.count(j)) continue;
                total++;
            }
        }
    }

    // Columns and diag1
    for (ll b : cols) {
        for (ll d : diag1) {
            ll i = b + d;
            if (i >= 1 && i <= N) {
                if (rows.count(i)) continue;
                total++;
            }
        }
    }

    // Columns and diag2
    for (ll b : cols) {
        for (ll s : diag2) {
            ll i = s - b;
            if (i >= 1 && i <= N) {
                if (rows.count(i)) continue;
                total++;
            }
        }
    }

    // Diag1 and diag2
    for (ll d : diag1) {
        for (ll s : diag2) {
            if ((s - d) % 2 != 0) continue;
            ll i = (s + d) / 2;
            ll j = (s - d) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) || cols.count(j)) continue;
                total++;
            }
        }
    }

    // Subtract triple intersections if any
    // Rows, columns, and diag1
    for (ll a : rows) {
        for (ll b : cols) {
            ll d = a - b;
            if (diag1.count(d)) {
                total--;
            }
        }
    }

    // Rows, columns, and diag2
    for (ll a : rows) {
        for (ll b : cols) {
            ll s = a + b;
            if (diag2.count(s)) {
                total--;
            }
        }
    }

    // Rows, diag1, and diag2
    for (ll a : rows) {
        for (ll d : diag1) {
            ll j = a - d;
            if (j < 1 || j > N) continue;
            ll s = a + j;
            if (diag2.count(s)) {
                if (!cols.count(j)) {
                    total--;
                }
            }
        }
    }

    // Columns, diag1, and diag2
    for (ll b : cols) {
        for (ll d : diag1) {
            ll i = b + d;
            if (i < 1 || i > N) continue;
            ll s = i + b;
            if (diag2.count(s)) {
                if (!rows.count(i)) {
                    total--;
                }
            }
        }
    }

    // Add back quadruple intersections
    for (ll a : rows) {
        for (ll b : cols) {
            ll d = a - b;
            ll s = a + b;
            if (diag1.count(d) && diag2.count(s)) {
                total++;
            }
        }
    }

    cout << total << endl;

    return 0;
}