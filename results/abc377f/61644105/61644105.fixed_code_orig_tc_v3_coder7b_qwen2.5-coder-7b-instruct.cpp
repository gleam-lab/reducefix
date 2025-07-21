#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    set<pair<long long, long long>> rows, cols, diags1, diags2;

    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert({x, y});
        cols.insert({y, x});
        diags1.insert({x + y, y});
        diags2.insert({x - y, y});
    }

    long long total_squares = n * n;
    long long occupied_squares = m;

    // Calculate squares occupied by pieces in rows, columns, and diagonals
    for (const auto& [r, c] : rows) {
        occupied_squares += n - 1;
    }
    for (const auto& [c, r] : cols) {
        occupied_squares += n - 1;
    }
    for (const auto& [d1, c] : diags1) {
        occupied_squares += n - 1;
    }
    for (const auto& [d2, c] : diags2) {
        occupied_squares += n - 1;
    }

    // Adjust for overcounted squares
    for (const auto& [r, c] : rows) {
        for (const auto& [c1, r1] : cols) {
            if (r == r1 || c == c1) continue;
            if (rows.find({r, c1}) != rows.end() ||
                cols.find({c, r1}) != cols.end()) {
                --occupied_squares;
            }
        }
        for (const auto& [d1, c1] : diags1) {
            if (r == r1 || c == c1) continue;
            if (diags1.find({d1, c1}) != diags1.end()) {
                --occupied_squares;
            }
        }
        for (const auto& [d2, c1] : diags2) {
            if (r == r1 || c == c1) continue;
            if (diags2.find({d2, c1}) != diags2.end()) {
                --occupied_squares;
            }
        }
    }

    cout << total_squares - occupied_squares << endl;

    return 0;
}