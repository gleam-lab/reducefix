#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total = N * N;
    i64 attacked = 0;
    
    // Rows and columns
    i64 row_count = rows.size();
    i64 col_count = cols.size();
    attacked += row_count * N + col_count * N - row_count * col_count;
    
    // Diagonals (i + j = const)
    for (auto d : diag1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (max_x >= min_x) {
            attacked += (max_x - min_x + 1);
        }
    }
    
    // Anti-diagonals (i - j = const)
    for (auto d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (max_x >= min_x) {
            attacked += (max_x - min_x + 1);
        }
    }
    
    // Intersections between rows/columns and diagonals/anti-diagonals
    for (auto d : diag1) {
        // Intersections with rows
        for (auto r : rows) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                attacked--;
            }
        }
        // Intersections with columns
        for (auto c : cols) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                attacked--;
            }
        }
    }
    
    for (auto d : diag2) {
        // Intersections with rows
        for (auto r : rows) {
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                attacked--;
            }
        }
        // Intersections with columns
        for (auto c : cols) {
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                attacked--;
            }
        }
    }
    
    // Intersections between diagonals and anti-diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked++;
            }
        }
    }
    
    // Subtract the M pieces themselves (they are already counted in the lines)
    attacked -= M;
    
    i64 safe = total - attacked;
    cout << safe << "\n";
    
    return 0;
}