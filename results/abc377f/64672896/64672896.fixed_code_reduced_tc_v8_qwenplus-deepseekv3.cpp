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
    set<pair<i64, i64>> occupied;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }
    i64 attacked = 0;
    // Rows
    attacked += rows.size() * N;
    // Columns
    attacked += cols.size() * N;
    // Diagonals (i + j = k)
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }
    // Anti-diagonals (i - j = k)
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }
    // Overlaps between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                attacked--;
            }
        }
    }
    // Overlaps between rows and diagonals
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag2.count(r - c)) {
                    attacked--;
                }
            }
        }
    }
    // Overlaps between columns and diagonals
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag2.count(r - c)) {
                    attacked--;
                }
            }
        }
    }
    // Overlaps between rows and anti-diagonals
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diag1.count(r + c)) {
                    attacked--;
                }
            }
        }
    }
    // Overlaps between columns and anti-diagonals
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 r = c + k;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diag1.count(r + c)) {
                    attacked--;
                }
            }
        }
    }
    // Overlaps between diagonals and anti-diagonals
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 == 0) {
                i64 r = (k1 + k2) / 2;
                i64 c = (k1 - k2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    if (rows.count(r) && cols.count(c)) {
                        attacked--;
                    }
                }
            }
        }
    }
    // Overlaps between all four conditions
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                attacked++;
            }
        }
    }
    // Subtract occupied squares since they are not empty
    i64 safe = N * N - attacked - M + occupied.size();
    cout << safe << endl;
    return 0;
}