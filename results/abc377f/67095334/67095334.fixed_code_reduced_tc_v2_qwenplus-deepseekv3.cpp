#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll unsafe_rows = rows.size() * N;
    ll unsafe_cols = cols.size() * N;
    ll unsafe_diag1 = 0;
    for (ll d : diag1) {
        ll len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        unsafe_diag1 += len;
    }
    ll unsafe_diag2 = 0;
    for (ll d : diag2) {
        ll len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }
        unsafe_diag2 += len;
    }
    
    ll unsafe_row_col_intersect = rows.size() * cols.size();
    ll unsafe_row_diag1_intersect = 0;
    for (ll d : diag1) {
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                unsafe_row_diag1_intersect++;
            }
        }
    }
    ll unsafe_row_diag2_intersect = 0;
    for (ll d : diag2) {
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                unsafe_row_diag2_intersect++;
            }
        }
    }
    ll unsafe_col_diag1_intersect = 0;
    for (ll d : diag1) {
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                unsafe_col_diag1_intersect++;
            }
        }
    }
    ll unsafe_col_diag2_intersect = 0;
    for (ll d : diag2) {
        for (ll c : cols) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                unsafe_col_diag2_intersect++;
            }
        }
    }
    ll unsafe_diag1_diag2_intersect = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                unsafe_diag1_diag2_intersect++;
            }
        }
    }
    
    ll unsafe_total = unsafe_rows + unsafe_cols + unsafe_diag1 + unsafe_diag2 
                     - unsafe_row_col_intersect - unsafe_row_diag1_intersect - unsafe_row_diag2_intersect 
                     - unsafe_col_diag1_intersect - unsafe_col_diag2_intersect + unsafe_diag1_diag2_intersect;
    
    ll total_safe = N * N - unsafe_total;
    cout << total_safe << endl;
    
    return 0;
}