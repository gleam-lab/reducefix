#include<bits/stdc++.h>

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
    
    ll total_safe = N * N;
    
    // Subtract squares in threatened rows and columns
    ll row_threat = rows.size() * N;
    ll col_threat = cols.size() * N;
    ll row_col_overlap = rows.size() * cols.size();
    total_safe -= (row_threat + col_threat - row_col_overlap);
    
    // Subtract squares in threatened diagonals (i-j and i+j)
    ll diag1_threat = 0;
    for (auto d : diag1) {
        // Number of squares where i - j = d
        // i ranges from max(1, 1 + d) to min(N, N + d)
        // j ranges accordingly
        ll upper_i = min(N, N + d);
        ll lower_i = max(1LL, 1LL + d);
        if (upper_i >= lower_i) {
            diag1_threat += (upper_i - lower_i + 1);
        }
    }
    
    ll diag2_threat = 0;
    for (auto d : diag2) {
        // Number of squares where i + j = d
        // i ranges from max(1, d - N) to min(N, d - 1)
        ll upper_i = min(N, d - 1);
        ll lower_i = max(1LL, d - N);
        if (upper_i >= lower_i) {
            diag2_threat += (upper_i - lower_i + 1);
        }
    }
    
    total_safe -= (diag1_threat + diag2_threat);
    
    // Add back squares that were double-counted (intersection of diagonals)
    // Also, squares already considered in row or column threats
    // This requires more detailed inclusion-exclusion
    
    // For each existing piece, the squares it threatens are:
    // row, column, diag1, diag2
    // The overlaps are:
    // 1. row and column: already accounted for in row_col_overlap
    // 2. row and diag1 or diag2: each existing piece has one such square (the piece's position)
    // 3. column and diag1 or diag2: same as above
    // 4. diag1 and diag2: only the piece's position
    
    // Number of such overlaps is M (each piece's position)
    // So, add back M to correct for over-subtraction
    total_safe += M;
    
    // Additionally, when subtracting diag1 and diag2 threats, some squares were subtracted
    // that are already in row or column threats. These squares are:
    // For each existing piece, the squares in its row or column that are also in its diag1 or diag2
    // This is complex, but a simpler approach is to calculate the exact overlaps
    
    // Instead, we can use inclusion-exclusion for each piece's threatened squares
    // But for M up to 1e3, we can afford to iterate through each piece and compute the union
    
    set<pair<ll, ll>> threatened;
    
    for (auto a : rows) {
        for (ll j = 1; j <= N; ++j) {
            threatened.insert({a, j});
        }
    }
    
    for (auto b : cols) {
        for (ll i = 1; i <= N; ++i) {
            threatened.insert({i, b});
        }
    }
    
    for (auto delta : diag1) {
        ll i_low = max(1LL, 1LL + delta);
        ll i_high = min(N, N + delta);
        if (i_high >= i_low) {
            for (ll i = i_low; i <= i_high; ++i) {
                ll j = i - delta;
                threatened.insert({i, j});
            }
        }
    }
    
    for (auto sum : diag2) {
        ll i_low = max(1LL, sum - N);
        ll i_high = min(N, sum - 1);
        if (i_high >= i_low) {
            for (ll i = i_low; i <= i_high; ++i) {
                ll j = sum - i;
                threatened.insert({i, j});
            }
        }
    }
    
    total_safe = N * N - threatened.size();
    
    cout << total_safe << endl;
    
    return 0;
}