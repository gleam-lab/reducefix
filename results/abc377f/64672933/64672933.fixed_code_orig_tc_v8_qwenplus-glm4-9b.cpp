#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Set to store coordinates of all captured points
    unordered_set<i64> captured_points;
    for (const auto& p : pieces) {
        captured_points.insert(p.first);
        captured_points.insert(p.second);
        captured_points.insert(p.first + p.second);
        captured_points.insert(abs(p.first - p.second));
    }

    // Count the number of captured points in each row, column, and diagonal
    vector<i64> row_count(N + 1, 0), col_count(N + 1, 0), diag1_count(2 * N + 1, 0), diag2_count(2 * N + 1, 0);
    for (const auto& p : pieces) {
        row_count[p.first]++;
        col_count[p.second]++;
        diag1_count[p.first + p.second]++;
        diag2_count[p.first - p.second]++;
    }

    i64 ans = N * N;
    for (i64 i = 1; i <= N; ++i) {
        // Subtract the number of captured points in each row, column, and diagonal
        ans -= row_count[i];
        ans -= col_count[i];
        ans -= diag1_count[i];
        ans -= diag2_count[i];

        // Adjust the counts for the next row and column
        row_count[i + 1]--;
        col_count[i + 1]--;
        diag1_count[i + 2]--;
        diag2_count[i - 1]--;
    }

    // Output the number of empty squares where you can place your piece
    cout << ans << "\n";
    return 0;
}