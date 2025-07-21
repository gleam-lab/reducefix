#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll total = N * N;
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll diag1_attacks = 0;
    for (ll d : diag1) {
        ll min_val = max(1LL, 1 + d - N);
        ll max_val = min(N, d - 1);
        if (min_val > max_val) continue;
        diag1_attacks += (max_val - min_val + 1);
    }
    ll diag2_attacks = 0;
    for (ll d : diag2) {
        ll min_val = max(1LL, 1 - d);
        ll max_val = min(N, N - d);
        if (min_val > max_val) continue;
        diag2_attacks += (max_val - min_val + 1);
    }

    total -= (row_attacks + col_attacks + diag1_attacks + diag2_attacks);

    // Add back intersections
    // row and col
    total += (ll)rows.size() * cols.size();

    // row and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                if (cols.find(c) != cols.end()) {
                    total--;
                }
            }
        }
    }

    // row and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                if (cols.find(c) != cols.end()) {
                    total--;
                }
            }
        }
    }

    // col and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                if (rows.find(r) != rows.end()) {
                    total--;
                }
            }
        }
    }

    // col and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                if (rows.find(r) != rows.end()) {
                    total--;
                }
            }
        }
    }

    // diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (1 <= r && r <= N && 1 <= c && c <= N) {
                    if (rows.find(r) != rows.end() && cols.find(c) != cols.end()) {
                        total++;
                    }
                }
            }
        }
    }

    cout << total << "\n";
    return 0;
}