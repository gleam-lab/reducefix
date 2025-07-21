#include<bits/stdc++.h>

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
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    // Total unsafe squares: rows + cols + diag1 + diag2 - intersections
    // But overlaps need to be handled carefully
    
    // Total squares under attack: |rows|*N + |cols|*N + |diag1|*(N - d1) + |diag2|*(N - d2) - overlaps
    // But this is complex, so better to calculate the distinct unsafe squares
    
    // The total unsafe squares is the union of all rows, columns, and diagonals
    // We can use inclusion-exclusion principle for the exact count, but it's complicated
    
    // Instead, approximate by adding individual counts and subtracting intersections
    // The exact formula is complex, but for large N, this approximation is acceptable
    
    // Calculate the number of squares attacked by rows
    ll row_attacked = unsafe_rows * N;
    
    // Calculate the number of squares attacked by columns (excluding those already counted in rows)
    ll col_attacked = unsafe_cols * (N - unsafe_rows);
    
    // Calculate the number of squares attacked by diag1 (i - j = c)
    // For each c in diag1, the number of squares is (N - abs(c)), but need to subtract those already counted in rows or cols
    ll diag1_attacked = 0;
    for (ll c : diag1) {
        ll cnt = N - abs(c);
        if (c >= 0) {
            // i ranges from 1 to N - c
            cnt = min(N, N - c) - max(1LL, 1LL - c) + 1;
        } else {
            // i ranges from 1 - c to N
            cnt = min(N, N - c) - max(1LL, 1LL - c) + 1;
        }
        diag1_attacked += cnt;
    }
    // Subtract squares already counted in rows or cols
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c)) {
                diag1_attacked--;
            }
        }
    }
    
    // Similarly for diag2 (i + j = c)
    ll diag2_attacked = 0;
    for (ll c : diag2) {
        ll cnt = min(N, c - 1) - max(1LL, c - N) + 1;
        diag2_attacked += cnt;
    }
    // Subtract squares already counted in rows or cols
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.count(r + c)) {
                diag2_attacked--;
            }
        }
    }
    
    // Also, subtract squares counted in both diag1 and diag2
    // These are the intersections of any two diagonals from diag1 and diag2
    // For each pair (d1, d2), there's at most one intersection point
    ll diag_intersect = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                diag_intersect++;
            }
        }
    }
    
    // Total unsafe squares: row_attacked + col_attacked + diag1_attacked + diag2_attacked - intersections
    // Intersections:
    // - squares in rows and cols: already subtracted in diag1_attacked and diag2_attacked
    // - squares in rows and diag1: counted once in row_attacked and once in diag1_attacked
    //   so subtract the count (number of diag1 squares in rows: for each c in diag1, check if (r, r - c) is in rows)
    // Similarly for other combinations
    
    // This is getting complex; for simplicity, we can use the inclusion-exclusion formula
    // Total unsafe squares = A + B + C + D - (A∩B + A∩C + A∩D + B∩C + B∩D + C∩D) + (A∩B∩C + A∩B∩D + A∩C∩D + B∩C∩D) - A∩B∩C∩D
    // Where A = rows, B = cols, C = diag1, D = diag2
    
    // Given the complexity, for large N and small M, it's better to compute the exact set of squares under attack
    
    // Instead, we can limit M to 1e3 and compute all squares under attack by any piece
    set<pair<ll, ll>> attacked;
    for (int k = 0; k < M; ++k) {
        ll a_k, b_k;
        cin >> a_k >> b_k;
        // All squares in row a_k
        for (ll j = 1; j <= N; ++j) {
            attacked.insert({a_k, j});
        }
        // All squares in column b_k
        for (ll i = 1; i <= N; ++i) {
            attacked.insert({i, b_k});
        }
        // All squares in diagonal i - j = a_k - b_k
        ll d1 = a_k - b_k;
        for (ll i = max(1LL, 1 + d1); i <= min(N, N + d1); ++i) {
            ll j = i - d1;
            attacked.insert({i, j});
        }
        // All squares in diagonal i + j = a_k + b_k
        ll d2 = a_k + b_k;
        for (ll i = max(1LL, d2 - N); i <= min(N, d2 - 1); ++i) {
            ll j = d2 - i;
            attacked.insert({i, j});
        }
    }
    
    // Total safe squares = Total empty squares - squares under attack
    ll total_empty = N * N - M;
    ll total_attacked = attacked.size();
    // But some attacked squares may be occupied by existing pieces, which are already excluded from total_empty
    // So the correct formula is (total_empty) - (total_attacked - M)
    // Because total_attacked includes M squares (the existing pieces)
    ll safe_squares = total_empty - (total_attacked - M);
    cout << safe_squares << endl;
    
    return 0;
}