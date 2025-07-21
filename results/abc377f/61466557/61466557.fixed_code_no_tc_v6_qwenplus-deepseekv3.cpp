#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool inBounds(ll i, ll j, ll n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    set<ll> rows, cols, d1, d2;
    set<pll> queen_positions;
    
    for (int i = 0; i < m; ++i) {
        cin >> queens[i].first >> queens[i].second;
        ll a = queens[i].first;
        ll b = queens[i].second;
        rows.insert(a);
        cols.insert(b);
        d1.insert(a - b);
        d2.insert(a + b);
        queen_positions.insert({a, b});
    }
    
    ll unsafe_rows = rows.size() * n;
    ll unsafe_cols = cols.size() * n;
    ll unsafe_d1 = 0;
    for (auto diag : d1) {
        ll cnt;
        if (diag >= 0) {
            cnt = n - diag;
        } else {
            cnt = n + diag;
        }
        unsafe_d1 += cnt;
    }
    ll unsafe_d2 = 0;
    for (auto diag : d2) {
        ll cnt;
        if (diag <= n + 1) {
            cnt = diag - 1;
        } else {
            cnt = 2 * n - diag + 1;
        }
        unsafe_d2 += cnt;
    }
    
    // Inclusion-Exclusion for rows and columns
    ll unsafe_rows_cols = rows.size() * cols.size();
    
    // Inclusion-Exclusion for rows and diagonals (d1)
    ll unsafe_rows_d1 = 0;
    for (auto diag : d1) {
        for (auto r : rows) {
            ll c = r - diag;
            if (inBounds(r, c, n)) {
                unsafe_rows_d1++;
            }
        }
    }
    
    // Inclusion-Exclusion for rows and diagonals (d2)
    ll unsafe_rows_d2 = 0;
    for (auto diag : d2) {
        for (auto r : rows) {
            ll c = diag - r;
            if (inBounds(r, c, n)) {
                unsafe_rows_d2++;
            }
        }
    }
    
    // Inclusion-Exclusion for columns and diagonals (d1)
    ll unsafe_cols_d1 = 0;
    for (auto diag : d1) {
        for (auto c : cols) {
            ll r = c + diag;
            if (inBounds(r, c, n)) {
                unsafe_cols_d1++;
            }
        }
    }
    
    // Inclusion-Exclusion for columns and diagonals (d2)
    ll unsafe_cols_d2 = 0;
    for (auto diag : d2) {
        for (auto c : cols) {
            ll r = diag - c;
            if (inBounds(r, c, n)) {
                unsafe_cols_d2++;
            }
        }
    }
    
    // Inclusion-Exclusion for diagonals d1 and d2
    ll unsafe_d1_d2 = 0;
    for (auto diag1 : d1) {
        for (auto diag2 : d2) {
            ll r = (diag1 + diag2) / 2;
            ll c = (diag2 - diag1) / 2;
            if ((diag1 + diag2) % 2 == 0 && (diag2 - diag1) % 2 == 0 && inBounds(r, c, n)) {
                unsafe_d1_d2++;
            }
        }
    }
    
    // Inclusion-Exclusion for rows, columns, and diagonals (d1)
    ll unsafe_rows_cols_d1 = 0;
    for (auto diag : d1) {
        for (auto r : rows) {
            ll c = r - diag;
            if (cols.count(c) && inBounds(r, c, n)) {
                unsafe_rows_cols_d1++;
            }
        }
    }
    
    // Inclusion-Exclusion for rows, columns, and diagonals (d2)
    ll unsafe_rows_cols_d2 = 0;
    for (auto diag : d2) {
        for (auto r : rows) {
            ll c = diag - r;
            if (cols.count(c) && inBounds(r, c, n)) {
                unsafe_rows_cols_d2++;
            }
        }
    }
    
    // Total unsafe squares
    ll total_unsafe = unsafe_rows + unsafe_cols + unsafe_d1 + unsafe_d2
                    - unsafe_rows_cols - unsafe_rows_d1 - unsafe_rows_d2 - unsafe_cols_d1 - unsafe_cols_d2 - unsafe_d1_d2
                    + unsafe_rows_cols_d1 + unsafe_rows_cols_d2;
    
    // Subtract the squares that are already occupied by queens (they are not empty)
    ll safe_squares = n * n - total_unsafe - m + queen_positions.size();
    
    cout << safe_squares << endl;
    
    return 0;
}