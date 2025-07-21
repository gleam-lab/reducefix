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
    
    // Squares not in any row, column, or diagonals with existing pieces
    ll safe_rows = N - rows.size();
    ll safe_cols = N - cols.size();
    ll total_safe = safe_rows * safe_cols;
    
    // Subtract squares that are in diagonals not already covered by rows or columns
    // For each diagonal type (a - b = k or a + b = k), count the squares not in rows or cols
    // but in the diagonal.
    
    // For a - b = k, the number of (i, j) where i - j = k, 1 <= i, j <= N
    // The range of k is -(N-1) to N-1
    // For a given k, number of valid (i, j) is N - |k|
    ll diag1_total = 0;
    for (auto k : diag1) {
        ll cnt = N - abs(k);
        ll overlap_rows = 0;
        ll overlap_cols = 0;
        // Calculate the number of squares in the diagonal that are also in forbidden rows or cols
        for (auto r : rows) {
            ll j = r - k;
            if (j >= 1 && j <= N) {
                overlap_rows++;
            }
        }
        for (auto c : cols) {
            ll i = c + k;
            if (i >= 1 && i <= N) {
                overlap_cols++;
            }
        }
        cnt -= overlap_rows + overlap_cols;
        diag1_total += cnt;
    }
    
    ll diag2_total = 0;
    for (auto k : diag2) {
        ll cnt = N - abs(k - (N + 1));
        if (k <= N + 1) {
            cnt = N - (N + 1 - k);
        } else {
            cnt = N - (k - (N + 1));
        }
        cnt = min(N, k - 1) - max(1LL, k - N) + 1;
        ll overlap_rows = 0;
        ll overlap_cols = 0;
        // Calculate the number of squares in the diagonal that are also in forbidden rows or cols
        for (auto r : rows) {
            ll j = k - r;
            if (j >= 1 && j <= N) {
                overlap_rows++;
            }
        }
        for (auto c : cols) {
            ll i = k - c;
            if (i >= 1 && i <= N) {
                overlap_cols++;
            }
        }
        cnt -= overlap_rows + overlap_cols;
        diag2_total += cnt;
    }
    
    total_safe -= diag1_total + diag2_total;
    
    // Now, add back squares that were subtracted twice (in both diagonals)
    // and not in any forbidden row or column
    set<pair<ll, ll>> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve i - j = d1 and i + j = d2
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                    intersections.insert({i, j});
                }
            }
        }
    }
    total_safe += intersections.size();
    
    cout << total_safe << endl;
    
    return 0;
}