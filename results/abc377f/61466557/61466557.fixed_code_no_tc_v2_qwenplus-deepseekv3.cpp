#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = N * N;
    ll attacked_rows = rows.size() * N;
    ll attacked_cols = cols.size() * N;
    ll attacked_diag1 = 0;
    ll attacked_diag2 = 0;

    for (auto d : diag1) {
        if (d >= 0) {
            attacked_diag1 += N - d;
        } else {
            attacked_diag1 += N + d;
        }
    }

    for (auto d : diag2) {
        if (d <= N + 1) {
            attacked_diag2 += d - 1;
        } else {
            attacked_diag2 += 2 * N - d + 1;
        }
    }

    ll overlaps_row_col = rows.size() * cols.size();
    ll overlaps_row_diag1 = 0;
    ll overlaps_row_diag2 = 0;
    ll overlaps_col_diag1 = 0;
    ll overlaps_col_diag2 = 0;
    ll overlaps_diag1_diag2 = 0;

    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                overlaps_row_diag1++;
            }
        }
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                overlaps_row_diag2++;
            }
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                overlaps_col_diag1++;
            }
        }
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                overlaps_col_diag2++;
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                overlaps_diag1_diag2++;
            }
        }
    }

    ll overlaps_row_col_diag1 = 0;
    ll overlaps_row_col_diag2 = 0;
    ll overlaps_row_diag1_diag2 = 0;
    ll overlaps_col_diag1_diag2 = 0;
    ll overlaps_all = 0;

    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r - c) != diag1.end()) {
                overlaps_row_col_diag1++;
            }
            if (diag2.find(r + c) != diag2.end()) {
                overlaps_row_col_diag2++;
            }
        }
    }

    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > N) continue;
            for (auto d2 : diag2) {
                if (r + c == d2 && c >= 1 && c <= N) {
                    overlaps_row_diag1_diag2++;
                }
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > N) continue;
            for (auto d2 : diag2) {
                if (r + c == d2 && r >= 1 && r <= N) {
                    overlaps_col_diag1_diag2++;
                }
            }
        }
    }

    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r - c) != diag1.end() && diag2.find(r + c) != diag2.end()) {
                overlaps_all++;
            }
        }
    }

    ll attacked_total = attacked_rows + attacked_cols + attacked_diag1 + attacked_diag2
                      - overlaps_row_col - overlaps_row_diag1 - overlaps_row_diag2
                      - overlaps_col_diag1 - overlaps_col_diag2 - overlaps_diag1_diag2
                      + overlaps_row_col_diag1 + overlaps_row_col_diag2 + overlaps_row_diag1_diag2
                      + overlaps_col_diag1_diag2 - overlaps_all;

    ll safe = total - attacked_total;
    cout << safe << endl;

    return 0;
}