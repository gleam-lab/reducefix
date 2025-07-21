#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (long long i = 0; i < n; ++i)

// Function to count safe squares
long long countSafeSquares(long long N, long long M, vector<pair<long long, long long>>& pieces) {
    unordered_set<long long> rows, cols, diag1, diag2;

    // Mark occupied rows, columns, and diagonals
    for (const auto& piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diag1.insert(piece.first - piece.second);
        diag2.insert(piece.first + piece.second);
    }

    // Calculate total number of squares
    long long total_squares = N * N;

    // Subtract the number of occupied squares
    total_squares -= rows.size() * N;
    total_squares -= cols.size() * N;

    // Add back the over-subtracted squares (those in both rows and columns)
    total_squares += rows.size() * cols.size();

    // Calculate capturable squares in diagonals
    for (long long d1 : diag1) {
        long long min_val = min(d1, N - 1);
        long long max_val = min(abs(d1), N - 1);
        total_squares -= (min_val + 1) * (max_val + 1);
    }

    for (long long d2 : diag2) {
        long long min_val = min(d2, 2 * N - 2);
        long long max_val = min(abs(d2), 2 * N - 2);
        total_squares -= (min_val + 1) * (max_val + 1);
    }

    // Add back the over-subtracted squares (those in both diagonals)
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            if (abs(d1 - d2) == N) {
                total_squares += 2 * (min(abs(d1), N - 1) + 1);
            }
        }
    }

    return total_squares;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    forn(i, M) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << countSafeSquares(N, M, pieces) << '\n';

    return 0;
}