#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1005

ll n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < m; ++i) {
        ll r, c;
        scanf("%lld %lld", &r, &c);
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(abs(r - c));
    }

    // Total squares are n*n
    ll total_squares = n * n;

    // Subtract squares that are covered by rows and columns
    ll covered_by_rows = rows.size();
    ll covered_by_cols = cols.size();
    ll covered_by_diag1 = diag1.size();
    ll covered_by_diag2 = diag2.size();

    // Subtract overlaps
    set<ll> all_covered;
    all_covered.insert(rows.begin(), rows.end());
    all_covered.insert(cols.begin(), cols.end());
    all_covered.insert(diag1.begin(), diag1.end());
    all_covered.insert(diag2.begin(), diag2.end());

    ll overlaps = all_covered.size();

    // Calculate the number of safe squares
    ll safe_squares = total_squares - covered_by_rows - covered_by_cols -
                       covered_by_diag1 - covered_by_diag2 + overlaps;

    printf("%lld\n", safe_squares);
    return 0;
}