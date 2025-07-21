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
    
    int total_rows = rows.size();
    int total_cols = cols.size();
    int total_diag1 = diag1.size();
    int total_diag2 = diag2.size();
    
    int total_threatened = 0;
    
    // Squares threatened by rows or columns
    total_threatened = total_rows * N + total_cols * (N - total_rows);
    
    // Squares threatened by diag1 (i+j = d)
    for (auto d : diag1) {
        int len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N - d + 1;
        }
        total_threatened += len;
    }
    
    // Squares threatened by diag2 (i-j = d)
    for (auto d : diag2) {
        int len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }
        total_threatened += len;
    }
    
    // Subtract intersections (squares counted multiple times)
    // Intersection between rows and columns
    total_threatened -= total_rows * total_cols;
    
    // Intersection between rows and diag1
    for (auto d : diag1) {
        int cnt = 0;
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                cnt++;
            }
        }
        total_threatened -= cnt;
    }
    
    // Intersection between rows and diag2
    for (auto d : diag2) {
        int cnt = 0;
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                cnt++;
            }
        }
        total_threatened -= cnt;
    }
    
    // Intersection between columns and diag1
    for (auto d : diag1) {
        int cnt = 0;
        for (auto c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                cnt++;
            }
        }
        total_threatened -= cnt;
    }
    
    // Intersection between columns and diag2
    for (auto d : diag2) {
        int cnt = 0;
        for (auto c : cols) {
            int r = d + c;
            if (1 <= r && r <= N) {
                cnt++;
            }
        }
        total_threatened -= cnt;
    }
    
    // Intersection between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= i && i <= N && 1 <= j && j <= N) {
                total_threatened--;
            }
        }
    }
    
    int total_safe = N * N - total_threatened - M;
    cout << total_safe << endl;
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