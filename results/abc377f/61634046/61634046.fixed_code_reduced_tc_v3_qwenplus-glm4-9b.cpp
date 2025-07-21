#include <iostream>
#include <vector>
#include <algorithm>

long long countNonCapturedSquares(int n, int m, const std::vector<std::pair<int, int>>& pieces) {
    if (m == 0) return (long long)n * n - 1;

    // Line vectors for row, column, diagonal, and antidiagonal
    std::vector<long long> rows(n + 1), cols(n + 1), diagonals(n + 1), antidiagonals(n + 1);
    
    for (const auto& piece : pieces) {
        int r = piece.first, c = piece.second;
        rows[r]++;
        cols[c]++;
        diagonals[r + c]++;
        antidiagonals[r - c + n]++;
    }

    long long nonCaptured = 0;

    // Subtract captured squares in each line
    for (int i = 1; i <= n; ++i) {
        nonCaptured -= (rows[i] - 1) * (cols[i] - 1) + (diagonals[i] - 1) * (antidiagonals[i] - 1);
    }

    // Total squares minus the number of captured squares
    return (long long)n * n - nonCaptured;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    std::cout << countNonCapturedSquares(n, m, pieces) << std::endl;

    return 0;
}