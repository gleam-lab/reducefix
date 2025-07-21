#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    set<int> rows, cols, diag1, diag2;
    set<pair<int, int>> pieces;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }
    
    // Calculate total forbidden squares
    int forbidden = 0;
    
    // Rows and columns
    forbidden += rows.size() * N + cols.size() * N - rows.size() * cols.size();
    
    // Diagonals of type i + j = d
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        forbidden += len;
        
        // Subtract intersections with rows and columns
        for (int i : rows) {
            if (i >= min_i && i <= max_i && (d - i) >= 1 && (d - i) <= N) {
                forbidden--;
            }
        }
        for (int j : cols) {
            if ((d - j) >= min_i && (d - j) <= max_i && j >= 1 && j <= N) {
                forbidden--;
            }
        }
    }
    
    // Diagonals of type i - j = d
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        forbidden += len;
        
        // Subtract intersections with rows and columns
        for (int i : rows) {
            if (i >= min_i && i <= max_i && (i - d) >= 1 && (i - d) <= N) {
                forbidden--;
            }
        }
        for (int j : cols) {
            if ((j + d) >= min_i && (j + d) <= max_i && j >= 1 && j <= N) {
                forbidden--;
            }
        }
    }
    
    // Subtract the intersections between diag1 and diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    forbidden--;
                }
            }
        }
    }
    
    // Add back the pieces since they were subtracted multiple times
    forbidden += M;
    
    // Total safe squares = total squares - forbidden squares + existing pieces (since they are already forbidden but not empty)
    int total_squares = N * N;
    int answer = total_squares - forbidden;
    
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