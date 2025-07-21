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
    
    int total_attacked = 0;
    
    // Rows and columns
    total_attacked += rows.size() * N + cols.size() * N - rows.size() * cols.size();
    
    // Diagonals type 1: i + j = d
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        total_attacked += len;
    }
    
    // Diagonals type 2: i - j = d
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        total_attacked += len;
    }
    
    // Overlaps between diagonals and rows/columns
    for (int d : diag1) {
        for (int r : rows) {
            if (1 <= d - r && d - r <= N) {
                total_attacked -= 1;
            }
        }
        for (int c : cols) {
            if (1 <= d - c && d - c <= N) {
                total_attacked -= 1;
            }
        }
    }
    
    for (int d : diag2) {
        for (int r : rows) {
            if (1 <= r - d && r - d <= N) {
                total_attacked -= 1;
            }
        }
        for (int c : cols) {
            if (1 <= c + d && c + d <= N) {
                total_attacked -= 1;
            }
        }
    }
    
    // Overlaps between diagonals type 1 and type 2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    total_attacked -= 1;
                }
            }
        }
    }
    
    int total_empty = N * N - M;
    int safe_squares = total_empty - (total_attacked - M);
    cout << safe_squares << endl;
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