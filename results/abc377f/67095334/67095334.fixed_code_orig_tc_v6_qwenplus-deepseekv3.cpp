#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)(r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

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

    int total_squares = N * N;
    int attacked_squares = 0;

    // Squares attacked by rows
    attacked_squares += rows.size() * N;
    
    // Squares attacked by columns, excluding those already counted in rows
    attacked_squares += cols.size() * (N - rows.size());
    
    // Squares attacked by diagonals i+j=d, excluding those already counted in rows or columns
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int count = max_i - min_i + 1;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                count--;
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                count--;
            }
        }
        // Add back intersections counted twice
        for (auto r : rows) {
            for (auto c : cols) {
                if (r + c == d) {
                    count++;
                }
            }
        }
        attacked_squares += max(0LL, count);
    }

    // Squares attacked by diagonals i-j=d, excluding those already counted in rows or columns or previous diagonals
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int count = max_i - min_i + 1;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                count--;
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                count--;
            }
        }
        // Add back intersections counted twice
        for (auto r : rows) {
            for (auto c : cols) {
                if (r - c == d) {
                    count++;
                }
            }
        }
        // Subtract intersections with diag1
        for (auto d1 : diag1) {
            if ((d1 + d) % 2 == 0) {
                int i = (d1 + d) / 2;
                int j = (d1 - d) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.count(i) || cols.count(j)) {
                        // Already accounted for in rows or cols
                    } else {
                        count--;
                    }
                }
            }
        }
        attacked_squares += max(0LL, count);
    }

    int safe_squares = total_squares - attacked_squares;
    cout << safe_squares << endl;
}

signed main() {
    int _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}