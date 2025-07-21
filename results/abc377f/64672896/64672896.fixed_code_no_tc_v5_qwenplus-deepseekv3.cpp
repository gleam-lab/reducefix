#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 attacked = 0;

    // Squares in the same row
    attacked += rows.size() * N;
    // Squares in the same column
    attacked += cols.size() * N;
    // Squares in the same diagonal (i + j = C)
    for (auto d : diag1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (min_x > max_x) continue;
        attacked += (max_x - min_x + 1);
    }
    // Squares in the same diagonal (i - j = C)
    for (auto d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (min_x > max_x) continue;
        attacked += (max_x - min_x + 1);
    }

    // Subtract overlaps between rows and columns (intersection is the piece itself)
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c})) continue;
            if (diag1.count(r + c) || diag2.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract overlaps between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c < 1 || c > N) continue;
            if (cols.count(c) || diag2.count(r - c)) continue;
            attacked -= 1;
        }
    }

    // Subtract overlaps between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c < 1 || c > N) continue;
            if (cols.count(c) || diag1.count(r + c)) continue;
            attacked -= 1;
        }
    }

    // Subtract overlaps between columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r < 1 || r > N) continue;
            if (rows.count(r) || diag2.count(r - c)) continue;
            attacked -= 1;
        }
    }

    // Subtract overlaps between columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r < 1 || r > N) continue;
            if (rows.count(r) || diag1.count(r + c)) continue;
            attacked -= 1;
        }
    }

    // Subtract overlaps between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            i64 r = (d1 + d2) / 2;
            i64 c = (d1 - d2) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (rows.count(r) || cols.count(c)) continue;
            attacked -= 1;
        }
    }

    // Add back the pieces themselves (since they were subtracted multiple times)
    attacked += M;

    i64 total = N * N;
    i64 safe = total - attacked;

    cout << safe << "\n";

    return 0;
}