#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> g(M);
    set<i64> rows, cols, diag1, diag2;
    set<array<i64, 2>> pieces;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }
    
    i64 unsafe = 0;
    
    // Rows
    unsafe += rows.size() * N;
    
    // Columns
    unsafe += cols.size() * N;
    
    // Diagonals (i + j = k)
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }
    
    // Anti-diagonals (i - j = k)
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }
    
    // Subtract overlaps: intersections of rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps: intersections of rows and diag1
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 c = k - r;
            if (c >= 1 && c <= N && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps: intersections of rows and diag2
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 c = r - k;
            if (c >= 1 && c <= N && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps: intersections of columns and diag1
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 r = k - c;
            if (r >= 1 && r <= N && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps: intersections of columns and diag2
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 r = c + k;
            if (r >= 1 && r <= N && pieces.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps: intersections of diag1 and diag2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 == 0) {
                i64 r = (k1 + k2) / 2;
                i64 c = (k1 - k2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N && pieces.count({r, c}) == 0) {
                    unsafe--;
                }
            }
        }
    }
    
    // Add back triple overlaps: squares that were subtracted three times
    for (auto r : rows) {
        for (auto c : cols) {
            i64 k1 = r + c;
            i64 k2 = r - c;
            if (diag1.count(k1) && diag2.count(k2) && pieces.count({r, c}) == 0) {
                unsafe += 1;
            }
        }
    }
    
    i64 safe = N * N - unsafe - M;
    cout << safe << "\n";
    
    return 0;
}