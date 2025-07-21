#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: a + b, diag2: a - b
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    
    // Subtract squares covered by rows, columns, diag1, diag2
    ll unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe += diag1.size() * N;
    unsafe += diag2.size() * N;
    
    // Add back intersections (row-col, row-diag1, row-diag2, col-diag1, col-diag2, diag1-diag2)
    ll row_col = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                row_col++;
            }
        }
    }
    unsafe -= row_col;
    
    ll row_diag1 = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N && cols.count(c)) {
                row_diag1++;
            }
        }
    }
    unsafe -= row_diag1;
    
    ll row_diag2 = 0;
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N && cols.count(c)) {
                row_diag2++;
            }
        }
    }
    unsafe -= row_diag2;
    
    ll col_diag1 = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N && rows.count(r)) {
                col_diag1++;
            }
        }
    }
    unsafe -= col_diag1;
    
    ll col_diag2 = 0;
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = c + d;
            if (1 <= r && r <= N && rows.count(r)) {
                col_diag2++;
            }
        }
    }
    unsafe -= col_diag2;
    
    ll diag1_diag2 = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                ll r = (d1 + d2) / 2;
                ll c = (d1 - d2) / 2;
                if (1 <= r && r <= N && 1 <= c && c <= N && rows.count(r) && cols.count(c)) {
                    diag1_diag2++;
                }
            }
        }
    }
    unsafe -= diag1_diag2;
    
    // Add intersections of three sets (row-col-diag1, row-col-diag2, etc.)
    // This is complex and may not be necessary here. Alternatively, we can find overlapping points.
    // For simplicity, we can compute the number of points covered by all four sets (row, col, diag1, diag2)
    ll all_covered = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                all_covered++;
            }
        }
    }
    unsafe += all_covered;
    
    ll safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}