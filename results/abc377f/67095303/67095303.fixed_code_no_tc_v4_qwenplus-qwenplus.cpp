#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total empty squares not on any attacked row or column
    int total = (n - rows.size()) * (n - cols.size());

    // Subtract squares attacked only by diagonals
    set<pair<int, int>> attacked_by_diagonals;

    for (auto d : diag1) {
        // For diagonal i+j=d
        // The valid range is max(1, d-n) <= i <= min(n, d-1)
        int min_i = max(1LL, d - n);
        int max_i = min(n, d - 1);
        
        if (min_i <= max_i) {
            // Check each point on this diagonal
            for (int i = min_i; i <= max_i; ++i) {
                int j = d - i;
                if (j >= 1 && j <= n && !rows.count(i) && !cols.count(j)) {
                    attacked_by_diagonals.insert({i, j});
                }
            }
        }
    }

    for (auto d : diag2) {
        // For diagonal i-j=d => i = j+d
        // So j must satisfy 1 <= j <= n and 1 <= j+d <= n
        int min_j = max(1LL, 1 - d);
        int max_j = min(n, n - d);
        
        if (min_j <= max_j) {
            for (int j = min_j; j <= max_j; ++j) {
                int i = j + d;
                if (i >= 1 && i <= n && !rows.count(i) && !cols.count(j)) {
                    attacked_by_diagonals.insert({i, j});
                }
            }
        }
    }

    cout << total - (int)attacked_by_diagonals.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}