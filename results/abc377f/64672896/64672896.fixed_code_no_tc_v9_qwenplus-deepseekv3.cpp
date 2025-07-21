#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;
    
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
        pieces.insert({a[i], b[i]});
    }
    
    i64 total_attacked = 0;
    
    // Squares attacked by rows
    total_attacked += rows.size() * N;
    
    // Squares attacked by columns
    total_attacked += cols.size() * N;
    
    // Squares attacked by diag1 (i + j = k)
    for (auto k : diag1) {
        i64 min_x_plus_y = max(1LL + 1LL, k - N);
        i64 max_x_plus_y = min(N + N, k);
        i64 count = max_x_plus_y - min_x_plus_y + 1;
        total_attacked += count;
    }
    
    // Squares attacked by diag2 (i - j = k)
    for (auto k : diag2) {
        i64 min_x_minus_y = max(1LL - N, k);
        i64 max_x_minus_y = min(N - 1LL, k);
        i64 count = N - abs(k);
        total_attacked += count;
    }
    
    // Subtract overlaps: squares counted in both rows and columns
    total_attacked -= rows.size() * cols.size();
    
    // Subtract overlaps: squares counted in rows and diag1
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 y = k - r;
            if (y >= 1 && y <= N) {
                total_attacked--;
            }
        }
    }
    
    // Subtract overlaps: squares counted in columns and diag1
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 x = k - c;
            if (x >= 1 && x <= N) {
                total_attacked--;
            }
        }
    }
    
    // Subtract overlaps: squares counted in rows and diag2
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 y = r - k;
            if (y >= 1 && y <= N) {
                total_attacked--;
            }
        }
    }
    
    // Subtract overlaps: squares counted in columns and diag2
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 x = c + k;
            if (x >= 1 && x <= N) {
                total_attacked--;
            }
        }
    }
    
    // Subtract overlaps: squares counted in diag1 and diag2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 == 0) {
                i64 x = (k1 + k2) / 2;
                i64 y = (k1 - k2) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    total_attacked--;
                }
            }
        }
    }
    
    // Add back squares subtracted multiple times (inclusion-exclusion principle)
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diag1.count(r + c) && diag2.count(r - c)) {
                total_attacked += 1;
            }
        }
    }
    
    // The result is total squares (N^2) minus the attacked squares, plus the squares already occupied (since they are not empty)
    i64 safe_squares = N * N - total_attacked + M - pieces.size();
    
    cout << safe_squares << "\n";
    
    return 0;
}