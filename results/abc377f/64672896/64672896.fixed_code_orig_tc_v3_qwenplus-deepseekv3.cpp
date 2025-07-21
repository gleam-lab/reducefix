#include<bits/stdc++.h>
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
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }

    i64 unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections counted twice

    // Diagonals i+j = k
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_min > x_max) continue;
        unsafe += x_max - x_min + 1;
    }

    // Diagonals i-j = k
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_min > x_max) continue;
        unsafe += x_max - x_min + 1;
    }

    // Subtract intersections between rows/cols and diag1/diag2
    for (auto a : rows) {
        for (auto k : diag1) {
            i64 b = k - a;
            if (b >= 1 && b <= N) {
                unsafe -= 1;
            }
        }
        for (auto k : diag2) {
            i64 b = a - k;
            if (b >= 1 && b <= N) {
                unsafe -= 1;
            }
        }
    }

    for (auto b : cols) {
        for (auto k : diag1) {
            i64 a = k - b;
            if (a >= 1 && a <= N) {
                unsafe -= 1;
            }
        }
        for (auto k : diag2) {
            i64 a = b + k;
            if (a >= 1 && a <= N) {
                unsafe -= 1;
            }
        }
    }

    // Add back squares counted in both diag1 and diag2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 != 0) continue;
            i64 a = (k1 + k2) / 2;
            i64 b = (k1 - k2) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe += 1;
            }
        }
    }

    // Subtract the actual pieces since they were counted multiple times
    unsafe -= M;

    i64 total = N * N;
    i64 safe = total - unsafe;

    cout << safe << "\n";

    return 0;
}