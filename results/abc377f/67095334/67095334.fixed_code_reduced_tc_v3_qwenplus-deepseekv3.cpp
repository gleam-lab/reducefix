#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int safe_rows = N - rows.size();
    int safe_cols = N - cols.size();
    int initial_safe = safe_rows * safe_cols;
    
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int diagonal_length = max_i - min_i + 1;
        
        set<int> covered_rows;
        for (auto r : rows) {
            if (1 <= d - r && d - r <= N) {
                covered_rows.insert(r);
            }
        }
        for (auto c : cols) {
            if (1 <= d - c && d - c <= N) {
                covered_rows.insert(d - c);
            }
        }
        
        int safe_in_diag = diagonal_length - covered_rows.size();
        initial_safe -= safe_in_diag;
    }
    
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int diagonal_length = max_i - min_i + 1;
        
        set<int> covered_rows;
        for (auto r : rows) {
            if (1 <= r - d && r - d <= N) {
                covered_rows.insert(r);
            }
        }
        for (auto c : cols) {
            if (1 <= c + d && c + d <= N) {
                covered_rows.insert(c + d);
            }
        }
        
        int safe_in_diag = diagonal_length - covered_rows.size();
        initial_safe -= safe_in_diag;
    }
    
    cout << initial_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int _ = 1;
    while (_--) {
        solve();
    }
    
    return 0;
}