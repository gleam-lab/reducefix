#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    unordered_set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    // Subtract intersections of rows and columns
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i+j)
    for (auto d : diag1) {
        i64 min_x_plus_y = max(1LL, d - N);
        i64 max_x_plus_y = min(N, d - 1);
        i64 count = max_x_plus_y - min_x_plus_y + 1;
        unsafe += count;
    }
    
    // Diagonals (i-j)
    for (auto d : diag2) {
        i64 min_x_minus_y = max(1LL - N, d);
        i64 max_x_minus_y = min(N - 1LL, d);
        i64 count = N - abs(d);
        unsafe += count;
    }
    
    // Subtract intersections between rows and diag1/diag2
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between columns and diag1/diag2
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
    }
    
    // Add back intersections between rows, columns, and diag1/diag2 that were subtracted multiple times
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                unsafe++;
            }
        }
    }
    
    // Subtract the original pieces themselves (they are occupied, not unsafe for placement)
    unsafe -= M;
    
    i64 total_safe = N * N - unsafe;
    cout << total_safe << "\n";
    
    return 0;
}