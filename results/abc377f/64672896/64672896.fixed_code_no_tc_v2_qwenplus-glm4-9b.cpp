#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> points(M);
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }

    // Sort points to find all unique rows, columns, diagonals
    sort(points.begin(), points.end());

    // Calculate the number of points in each row, column, and diagonals
    vector<i64> row_count(N + 1, 0);
    vector<i64> col_count(N + 1, 0);
    vector<i64> diag1_count(2 * N + 1, 0); // i + j
    vector<i64> diag2_count(2 * N + 1, 0); // i - j

    for (const auto& point : points) {
        row_count[point.first]++;
        col_count[point.second]++;
        diag1_count[point.first + point.second]++;
        diag2_count[point.first - point.second]++;
    }

    // Calculate the number of capture patterns
    i64 total_captures = 0;
    for (i64 i = 1; i <= N; ++i) {
        total_captures += max(row_count[i], 1LL);
        total_captures += max(col_count[i], 1LL);
        total_captures += max(diag1_count[i], 1LL);
        total_captures += max(diag2_count[i], 1LL);
    }

    // Subtract the number of squares occupied by pieces
    total_captures += M;

    // Calculate the number of safe squares
    i64 ans = (N * N) - total_captures;

    cout << ans << "\n";

    return 0;
}