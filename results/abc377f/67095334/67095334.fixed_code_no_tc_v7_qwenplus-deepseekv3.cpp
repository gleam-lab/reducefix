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
    
    int total = N * N;
    int forbidden = 0;
    
    // Forbidden squares due to rows and columns
    int row_count = rows.size();
    int col_count = cols.size();
    forbidden += row_count * N + col_count * N - row_count * col_count;
    
    // Forbidden squares due to diag1 (i + j = d)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int len = max_i - min_i + 1;
        forbidden += len;
        
        // Subtract squares already forbidden in rows or columns
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                forbidden--;
            }
        }
        for (auto c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                forbidden--;
            }
        }
        // Add back squares subtracted twice (both row and column)
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= N && cols.count(c)) {
                forbidden++;
            }
        }
    }
    
    // Forbidden squares due to diag2 (i - j = d)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        int len = max_i - min_i + 1;
        forbidden += len;
        
        // Subtract squares already forbidden in rows or columns
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                forbidden--;
            }
        }
        for (auto c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) {
                forbidden--;
            }
        }
        // Add back squares subtracted twice (both row and column)
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= N && cols.count(c)) {
                forbidden++;
            }
        }
    }
    
    // Subtract squares that were added in both diagonals (i,j) where both diag1 and diag2 are occupied
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (1 <= i && i <= N && 1 <= j && j <= N) {
                forbidden--;
            }
        }
    }
    
    int answer = total - forbidden;
    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}