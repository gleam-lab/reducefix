#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    unordered_set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll total_squares = N * N;

    ll attacked_rows = rows.size() * N;
    ll attacked_cols = cols.size() * N;
    ll attacked_diag1 = 0;
    for (ll d : diag1) {
        ll min_val = max(1LL, d - N);
        ll max_val = min(N, d - 1);
        if (min_val <= max_val) {
            attacked_diag1 += (max_val - min_val + 1);
        }
    }
    ll attacked_diag2 = 0;
    for (ll d : diag2) {
        ll min_val = max(1LL, 1 - d);
        ll max_val = min(N, N - d);
        if (min_val <= max_val) {
            attacked_diag2 += (max_val - min_val + 1);
        }
    }

    ll row_col_intersect = rows.size() * cols.size();
    ll row_diag1_intersect = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (c >= 1 && c <= N && cols.count(c)) {
                row_diag1_intersect++;
            }
        }
    }
    ll row_diag2_intersect = 0;
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (c >= 1 && c <= N && cols.count(c)) {
                row_diag2_intersect++;
            }
        }
    }
    ll col_diag1_intersect = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (r >= 1 && r <= N && rows.count(r)) {
                col_diag1_intersect++;
            }
        }
    }
    ll col_diag2_intersect = 0;
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = c + d;
            if (r >= 1 && r <= N && rows.count(r)) {
                col_diag2_intersect++;
            }
        }
    }
    ll diag1_diag2_intersect = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N && rows.count(r) && cols.count(c)) {
                diag1_diag2_intersect++;
            }
        }
    }

    ll row_col_diag1_intersect = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                row_col_diag1_intersect++;
            }
        }
    }

    ll total_attacked = attacked_rows + attacked_cols + attacked_diag1 + attacked_diag2
                      - row_col_intersect - row_diag1_intersect - row_diag2_intersect - col_diag1_intersect - col_diag2_intersect - diag1_diag2_intersect
                      + row_col_diag1_intersect;

    ll safe_squares = total_squares - total_attacked;

    cout << safe_squares << endl;

    return 0;
}