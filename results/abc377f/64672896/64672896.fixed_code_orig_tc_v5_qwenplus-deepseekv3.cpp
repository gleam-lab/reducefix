#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 threatened = 0;
    
    // Squares in threatened rows
    threatened += N * rows.size();
    
    // Squares in threatened columns
    threatened += N * cols.size();
    
    // Squares in threatened diagonals (i + j = k)
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max >= x_min) {
            threatened += x_max - x_min + 1;
        }
    }
    
    // Squares in threatened anti-diagonals (i - j = k)
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max >= x_min) {
            threatened += x_max - x_min + 1;
        }
    }
    
    // Subtract intersections: squares counted in both rows and columns
    threatened -= rows.size() * cols.size();
    
    // Subtract intersections: squares counted in both rows and diag1
    for (auto a : rows) {
        for (auto k : diag1) {
            i64 b = k - a;
            if (b >= 1 && b <= N) {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections: squares counted in both rows and diag2
    for (auto a : rows) {
        for (auto k : diag2) {
            i64 b = a - k;
            if (b >= 1 && b <= N) {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections: squares counted in both columns and diag1
    for (auto b : cols) {
        for (auto k : diag1) {
            i64 a = k - b;
            if (a >= 1 && a <= N) {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections: squares counted in both columns and diag2
    for (auto b : cols) {
        for (auto k : diag2) {
            i64 a = k + b;
            if (a >= 1 && a <= N) {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections: squares counted in both diag1 and diag2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 - k2) % 2 == 0) {
                i64 a = (k1 + k2) / 2;
                i64 b = (k1 - k2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    threatened -= 1;
                }
            }
        }
    }
    
    // Add back squares that were subtracted multiple times (inclusion-exclusion principle)
    // Squares at the intersection of rows, columns, diag1, and diag2 (i.e., the piece positions)
    threatened += M;
    
    // Total safe squares = total squares - threatened squares - occupied squares + squares that are both threatened and occupied
    // But occupied squares are already included in threatened squares, so:
    i64 safe = N * N - threatened;
    
    cout << safe << "\n";
    
    return 0;
}