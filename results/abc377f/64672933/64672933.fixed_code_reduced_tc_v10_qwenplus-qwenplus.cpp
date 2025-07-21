#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    
    set<pair<i64, i64>> pieces;
    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares attacked by existing pieces
    // We'll count all unique cells attacked by any of the lines
    map<pair<i64, i64>, i64> attack_counts;

    auto add_attack = [&](i64 r, i64 c) {
        if (r >= 1 && r <= N && c >= 1 && c <= N && !pieces.count({r, c})) {
            attack_counts[{r, c}]++;
        }
    };

    // For each piece, mark all cells it can attack
    for (auto [a, b] : pieces) {
        // Row
        for (i64 j = 1; j <= N; ++j) {
            if (j != b) add_attack(a, j);
        }
        // Column
        for (i64 i = 1; i <= N; ++i) {
            if (i != a) add_attack(i, b);
        }

        // Diagonal 1 (a + b)
        i64 d1 = a + b;
        i64 start = max(1LL, d1 - N);
        i64 end = min(N, d1 - 1);
        for (i64 x = start; x <= end; ++x) {
            i64 y = d1 - x;
            if (x != a && y != b) add_attack(x, y);
        }

        // Diagonal 2 (a - b)
        i64 d2 = a - b;
        start = max(1LL, d2 > 0 ? d2 : 1);
        end = min(N, N + d2 > 0 ? N : d2 + N);
        for (i64 x = start; x <= end; ++x) {
            i64 y = x - d2;
            if (y >= 1 && y <= N && x != a && y != b) {
                add_attack(x, y);
            }
        }
    }

    // Total squares that are attacked
    i64 attacked_squares = attack_counts.size();

    // Total empty squares = total - occupied
    i64 total_empty = N * N - pieces.size();

    // Answer = empty squares - attacked empty squares
    cout << total_empty - attacked_squares << "\n";

    return 0;
}