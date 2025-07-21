#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    unordered_set<int> rows, cols, diag1, diag2;
    
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
    int total = safe_rows * safe_cols;
    
    // For each diagonal (i+j), subtract the squares not already covered by rows or columns
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        
        unordered_set<int> covered;
        for (int x : rows) {
            if (1 <= d - x && d - x <= N) {
                covered.insert(x);
            }
        }
        for (int y : cols) {
            if (1 <= d - y && d - y <= N) {
                covered.insert(d - y);
            }
        }
        
        total -= (len - covered.size());
    }
    
    // For each diagonal (i-j), subtract the squares not already covered by rows or columns
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        
        unordered_set<int> covered;
        for (int x : rows) {
            if (1 <= x - d && x - d <= N) {
                covered.insert(x);
            }
        }
        for (int y : cols) {
            if (1 <= y + d && y + d <= N) {
                covered.insert(y + d);
            }
        }
        
        total -= (len - covered.size());
    }
    
    cout << total << endl;
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