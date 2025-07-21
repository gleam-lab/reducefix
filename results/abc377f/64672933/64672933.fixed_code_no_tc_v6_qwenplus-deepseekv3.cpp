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
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    i64 forbidden = 0;
    // Rows: each row contributes N squares, but we have 'rows.size()' unique rows
    forbidden += rows.size() * N;
    // Columns: each column contributes N squares, but overlaps with rows are already counted once per piece
    forbidden += cols.size() * N;
    // Diagonals (i + j = a + b): each diagonal contributes the number of squares on it
    for (auto d : diag1) {
        i64 min_xy = max(1LL, d - N);
        i64 max_xy = min(N, d - 1);
        if (min_xy > max_xy) continue;
        forbidden += (max_xy - min_xy + 1);
    }
    // Diagonals (i - j = a - b): each diagonal contributes the number of squares on it
    for (auto d : diag2) {
        i64 min_xy = max(1LL, 1 - d);
        i64 max_xy = min(N, N - d);
        if (min_xy > max_xy) continue;
        forbidden += (max_xy - min_xy + 1);
    }
    // Now, subtract overlaps between rows and columns (each piece's position is counted twice)
    forbidden -= rows.size() * cols.size();
    // Subtract overlaps between rows and diag1 (each piece's position is counted twice)
    for (auto d : diag1) {
        i64 a_plus_b = d;
        for (auto a : rows) {
            i64 b = a_plus_b - a;
            if (cols.count(b)) {
                forbidden--;
            }
        }
    }
    // Subtract overlaps between rows and diag2 (each piece's position is counted twice)
    for (auto d : diag2) {
        i64 a_minus_b = d;
        for (auto a : rows) {
            i64 b = a - a_minus_b;
            if (cols.count(b)) {
                forbidden--;
            }
        }
    }
    // Subtract overlaps between columns and diag1 (each piece's position is counted twice)
    for (auto d : diag1) {
        i64 a_plus_b = d;
        for (auto b : cols) {
            i64 a = a_plus_b - b;
            if (rows.count(a)) {
                forbidden--;
            }
        }
    }
    // Subtract overlaps between columns and diag2 (each piece's position is counted twice)
    for (auto d : diag2) {
        i64 a_minus_b = d;
        for (auto b : cols) {
            i64 a = a_minus_b + b;
            if (rows.count(a)) {
                forbidden--;
            }
        }
    }
    // Subtract overlaps between diag1 and diag2 (each piece's position is counted twice)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 a = (d1 + d2) / 2;
            i64 b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                if (rows.count(a) && cols.count(b)) {
                    forbidden--;
                }
            }
        }
    }
    // Total safe squares
    i64 total = N * N;
    i64 safe = total - forbidden;
    cout << safe << "\n";
    return 0;
}