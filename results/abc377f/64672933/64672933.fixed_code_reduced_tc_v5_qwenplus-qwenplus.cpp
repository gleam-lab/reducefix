#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.emplace(a, b);
    }

    // Total forbidden positions due to being in same row, col, or diagonal
    i64 total_forbidden = 0;

    // Count how many squares are covered by at least one direction
    total_forbidden += rows.size() * N;
    total_forbidden += cols.size() * N;
    for (auto d : diag1) {
        // Number of cells on diagonal a+b=d
        i64 count;
        if (d <= N + 1) {
            count = d - 1;
        } else {
            count = 2 * N + 1 - d;
        }
        total_forbidden += count;
    }
    for (auto d : diag2) {
        // Number of cells on diagonal a-b=d
        i64 count;
        if (d >= 0) {
            count = N - d;
        } else {
            count = N + d;
        }
        total_forbidden += count;
    }

    // Subtract overlaps: cell counted multiple times
    // For each piece, it lies in all four directions, so subtract duplicates
    total_forbidden -= 3 * M;

    // Now calculate available positions
    i64 total_positions = N * N;
    i64 available = total_positions - total_forbidden + M;

    cout << available << "\n";

    return 0;
}