#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 total_safe = N * N;
    
    // Subtract squares attacked by rows
    total_safe -= N * rows.size();
    
    // Subtract squares attacked by columns
    total_safe -= N * cols.size();
    
    // Add back squares that were subtracted twice (intersection of row and column)
    total_safe += rows.size() * cols.size();
    
    // Subtract squares attacked by diagonal 1 (i + j = constant)
    for (auto d : diag1) {
        i64 L = max(1LL, d - N);
        i64 R = min(N, d - 1);
        if (R >= L) {
            total_safe -= (R - L + 1);
        }
    }
    
    // Subtract squares attacked by diagonal 2 (i - j = constant)
    for (auto d : diag2) {
        i64 L = max(1LL, 1 - d);
        i64 R = min(N, N - d);
        if (R >= L) {
            total_safe -= (R - L + 1);
        }
    }
    
    // Add back squares subtracted twice by diagonals and rows/columns
    // Intersection of row and diagonal 1: for each row a in rows, and d in diag1, if (a + b = d) => b = d - a
    for (auto a : rows) {
        for (auto d : diag1) {
            i64 b = d - a;
            if (b >= 1 && b <= N) {
                total_safe += 1;
            }
        }
    }
    
    // Intersection of row and diagonal 2: for each row a in rows, and d in diag2, if (a - b = d) => b = a - d
    for (auto a : rows) {
        for (auto d : diag2) {
            i64 b = a - d;
            if (b >= 1 && b <= N) {
                total_safe += 1;
            }
        }
    }
    
    // Intersection of column and diagonal 1: for each column b in cols, and d in diag1, if (a + b = d) => a = d - b
    for (auto b : cols) {
        for (auto d : diag1) {
            i64 a = d - b;
            if (a >= 1 && a <= N) {
                total_safe += 1;
            }
        }
    }
    
    // Intersection of column and diagonal 2: for each column b in cols, and d in diag2, if (a - b = d) => a = b + d
    for (auto b : cols) {
        for (auto d : diag2) {
            i64 a = b + d;
            if (a >= 1 && a <= N) {
                total_safe += 1;
            }
        }
    }
    
    // Subtract intersections counted twice (both diagonals)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve a + b = d1 and a - b = d2 => a = (d1 + d2)/2, b = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                i64 a = (d1 + d2) / 2;
                i64 b = (d1 - d2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    total_safe -= 1;
                }
            }
        }
    }
    
    // Subtract the occupied squares if they were counted as safe
    total_safe += occupied.size();
    
    cout << max(total_safe, 0LL) << "\n";
    
    return 0;
}