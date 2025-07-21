#include <bits/stdc++.h>
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
    
    int row_count = rows.size();
    int col_count = cols.size();
    int diag1_count = diag1.size();
    int diag2_count = diag2.size();
    
    // Total safe squares not in any attacked row or column
    int safe = (N - row_count) * (N - col_count);
    
    // Subtract squares under attack by diagonals not already covered by rows/columns
    for (int d : diag1) {
        int min_xy = max(1LL, d - N);
        int max_xy = min(N, d - 1);
        int len = max_xy - min_xy + 1;
        
        int cnt = len;
        for (int x : rows) {
            int y = d - x;
            if (y >= 1 && y <= N) {
                cnt--;
            }
        }
        for (int y : cols) {
            int x = d - y;
            if (x >= 1 && x <= N) {
                cnt--;
            }
        }
        safe -= max(0LL, cnt);
    }
    
    for (int d : diag2) {
        int min_xy = max(1LL, 1 - d);
        int max_xy = min(N, N - d);
        int len = max_xy - min_xy + 1;
        
        int cnt = len;
        for (int x : rows) {
            int y = x - d;
            if (y >= 1 && y <= N) {
                cnt--;
            }
        }
        for (int y : cols) {
            int x = d + y;
            if (x >= 1 && x <= N) {
                cnt--;
            }
        }
        safe -= max(0LL, cnt);
    }
    
    // Add back squares subtracted twice (intersection of diagonals)
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int x = (d1 + d2) / 2;
            int y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    if (rows.count(x) == 0 && cols.count(y) == 0) {
                        safe++;
                    }
                }
            }
        }
    }
    
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}