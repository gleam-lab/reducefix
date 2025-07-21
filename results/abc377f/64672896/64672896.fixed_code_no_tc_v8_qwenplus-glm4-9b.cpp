#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<int, 2>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i][0] >> pieces[i][1];
    }

    // We need to consider the total number of squares minus the squares that are constrained by existing pieces.
    i64 total_squares = N * N;
    i64 constrained_squares = 0;

    // We calculate the number of constrained squares by considering all possible constraints given by the existing pieces.
    vector<i64> rows(N + 1, 0), cols(N + 1, 0), diag1(N + 1, 0), diag2(N + 1, 0);
    
    for (const auto& p : pieces) {
        rows[p[0]]++;
        cols[p[1]]++;
        diag1[p[0] + p[1]]++;
        diag2[p[0] - p[1]]++;
    }

    // Add the number of constrained squares from rows and columns.
    for (i64 i = 1; i <= N; ++i) {
        constrained_squares += rows[i] + cols[i];
    }
    // Subtract the intersections because they are counted twice.
    constrained_squares -= diag1.size() - 1; // Only subtract the diagonals, without the empty diagonal.

    // We also need to account for the constraints imposed by the diagonals.
    for (i64 i = 1; i <= N; ++i) {
        constrained_squares += diag1[i] + diag2[i];
    }

    // The number of valid empty squares is the total number of squares minus the number of constrained squares.
    i64 valid_squares = total_squares - constrained_squares;
    cout << valid_squares << "\n";

    return 0;
}