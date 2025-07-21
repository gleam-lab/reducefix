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
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract overlaps

    // Diagonals (a+b and a-b)
    unsafe += diag1.size() * N;
    for (auto d : diag1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (max_x < min_x) continue;
        unsafe -= (max_x - min_x + 1);
    }

    unsafe += diag2.size() * N;
    for (auto d : diag2) {
        i64 min_x = max(1LL, 1 - d);
        i64 max_x = min(N, N - d);
        if (max_x < min_x) continue;
        unsafe -= (max_x - min_x + 1);
    }

    // Overlaps between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
    }

    // Overlaps between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
    }

    // Overlaps between cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
    }

    // Overlaps between cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
    }

    // Overlaps between diag1 and diag2
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

    // Finally, subtract the occupied squares that were counted multiple times
    unsafe -= M;

    i64 total_safe = N * N - unsafe;
    cout << total_safe << "\n";

    return 0;
}