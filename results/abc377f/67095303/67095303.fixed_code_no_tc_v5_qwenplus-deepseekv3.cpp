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
    
    ll total_safe = N * N - M;
    
    // Subtract squares covered by rows
    ll covered_by_rows = rows.size() * N;
    // Subtract squares covered by columns, excluding those already in rows
    ll covered_by_cols = cols.size() * (N - rows.size());
    // Now, the squares covered by both rows and columns are already subtracted once, so no adjustment needed
    
    ll covered_lines = covered_by_rows + covered_by_cols;
    
    // Now handle the diagonals
    // For each diagonal in diag1, calculate the number of squares not covered by rows or columns
    for (ll d : diag1) {
        ll min_i = max(1LL, d - N);
        ll max_i = min(N, d - 1);
        ll count = max_i - min_i + 1;
        
        // Subtract squares already covered by rows or columns
        for (ll i = min_i; i <= max_i; ++i) {
            ll j = d - i;
            if (rows.count(i) || cols.count(j)) {
                count--;
            }
        }
        
        covered_lines += count;
    }
    
    // For each diagonal in diag2, calculate the number of squares not covered by rows, columns, or diag1
    for (ll d : diag2) {
        ll min_i = max(1LL, 1 + d);
        ll max_i = min(N, N + d);
        ll count = max_i - min_i + 1;
        
        // Subtract squares already covered by rows or columns
        for (ll i = min_i; i <= max_i; ++i) {
            ll j = i - d;
            if (rows.count(i) || cols.count(j)) {
                count--;
            }
        }
        
        // Subtract squares also covered by diag1
        for (ll i = min_i; i <= max_i; ++i) {
            ll j = i - d;
            if (diag1.count(i + j)) {
                if (!rows.count(i) && !cols.count(j)) {
                    count--;
                }
            }
        }
        
        covered_lines += count;
    }
    
    total_safe -= covered_lines;
    
    cout << total_safe << endl;
    
    return 0;
}