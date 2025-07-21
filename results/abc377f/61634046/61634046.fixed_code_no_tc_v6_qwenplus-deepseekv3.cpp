#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
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
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    // Total unsafe squares: rows + cols + diag1 + diag2 - intersections
    // Using inclusion-exclusion principle
    ll total_unsafe = unsafe_rows * N + unsafe_cols * N;
    
    for (ll d : diag1) {
        ll count = 0;
        // Diagonal i+j = d
        // i ranges from max(1, d - N) to min(N, d - 1)
        ll i_min = max(1LL, d - N);
        ll i_max = min(N, d - 1);
        if (i_min > i_max) continue;
        count += i_max - i_min + 1;
        total_unsafe += count;
    }
    
    for (ll d : diag2) {
        ll count = 0;
        // Diagonal i-j = d
        // i ranges from max(1, 1 + d) to min(N, N + d)
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        count += i_max - i_min + 1;
        total_unsafe += count;
    }
    
    // Subtract intersections: rows ∩ cols, rows ∩ diag1, rows ∩ diag2, cols ∩ diag1, cols ∩ diag2, diag1 ∩ diag2
    ll row_col = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (rows.count(r) && cols.count(c)) {
                row_col++;
            }
        }
    }
    total_unsafe -= row_col;
    
    ll row_diag1 = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (rows.count(r) && diag1.count(r + c)) {
                    row_diag1++;
                }
            }
        }
    }
    total_unsafe -= row_diag1;
    
    ll row_diag2 = 0;
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (rows.count(r) && diag2.count(r - c)) {
                    row_diag2++;
                }
            }
        }
    }
    total_unsafe -= row_diag2;
    
    ll col_diag1 = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (cols.count(c) && diag1.count(r + c)) {
                    col_diag1++;
                }
            }
        }
    }
    total_unsafe -= col_diag1;
    
    ll col_diag2 = 0;
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                if (cols.count(c) && diag2.count(r - c)) {
                    col_diag2++;
                }
            }
        }
    }
    total_unsafe -= col_diag2;
    
    ll diag1_diag2 = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (diag1.count(i + j) && diag2.count(i - j)) {
                    diag1_diag2++;
                }
            }
        }
    }
    total_unsafe -= diag1_diag2;
    
    // Add back triple intersections
    ll row_col_diag1 = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c)) {
                row_col_diag1++;
            }
        }
    }
    total_unsafe += row_col_diag1;
    
    ll row_col_diag2 = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.count(r - c)) {
                row_col_diag2++;
            }
        }
    }
    total_unsafe += row_col_diag2;
    
    ll row_diag1_diag2 = 0;
    for (ll r : rows) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll i = (d1 + d2) / 2;
                ll j = (d1 - d2) / 2;
                if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N && i == r) {
                    if (diag1.count(i + j) && diag2.count(i - j)) {
                        row_diag1_diag2++;
                    }
                }
            }
        }
    }
    total_unsafe += row_diag1_diag2;
    
    ll col_diag1_diag2 = 0;
    for (ll c : cols) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll i = (d1 + d2) / 2;
                ll j = (d1 - d2) / 2;
                if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N && j == c) {
                    if (diag1.count(i + j) && diag2.count(i - j)) {
                        col_diag1_diag2++;
                    }
                }
            }
        }
    }
    total_unsafe += col_diag1_diag2;
    
    // Subtract quadruple intersection
    ll row_col_diag1_diag2 = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                row_col_diag1_diag2++;
            }
        }
    }
    total_unsafe -= row_col_diag1_diag2;
    
    ll total_safe = N * N - total_unsafe + M; // Since existing pieces are already counted as unsafe but are not empty
    cout << total_safe << endl;
    
    return 0;
}