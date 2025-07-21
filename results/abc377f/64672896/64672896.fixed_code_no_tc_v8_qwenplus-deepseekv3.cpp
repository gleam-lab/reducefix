#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 unsafe = 0;
    
    // Count squares attacked by rows
    unsafe += rows.size() * N;
    
    // Count squares attacked by cols, subtract intersections with rows
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    // Count squares attacked by diag1 (i + j = d1)
    for (auto d1 : diag1) {
        i64 x_min = max(1LL, d1 - N);
        i64 x_max = min(N, d1 - 1);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }
    
    // Count squares attacked by diag2 (i - j = d2)
    for (auto d2 : diag2) {
        i64 x_min = max(1LL, 1 + d2);
        i64 x_max = min(N, N + d2);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }
    
    // Subtract overlaps between diag1 and rows/cols
    for (auto d1 : diag1) {
        for (auto r : rows) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps between diag2 and rows/cols
    for (auto d2 : diag2) {
        for (auto r : rows) {
            i64 c = r - d2;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            i64 r = c + d2;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Add overlaps between diag1 and diag2 (intersection points)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 x = (d1 + d2) / 2;
                i64 y = (d1 - d2) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    unsafe++;
                }
            }
        }
    }
    
    // Subtract the squares occupied by existing pieces (since they are already counted multiple times)
    unsafe -= M;
    
    i64 total_squares = N * N;
    i64 safe_squares = total_squares - unsafe;
    
    cout << safe_squares << "\n";
    
    return 0;
}