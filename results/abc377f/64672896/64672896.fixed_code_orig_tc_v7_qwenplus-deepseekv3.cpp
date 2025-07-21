#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 forbidden = 0;

    // Rows and columns are straightforward: each forbids N positions
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;

    // Diagonals: each forbids the number of positions on the diagonal
    // For diag1 (a + b = k): the number of positions is min(k - 1, 2N - k + 1) for 2 <= k <= 2N
    for (auto k : diag1) {
        i64 cnt;
        if (k <= N + 1) {
            cnt = k - 1;
        } else {
            cnt = 2 * N - k + 1;
        }
        forbidden += cnt;
    }

    // For diag2 (a - b = k): the number of positions is N - abs(k) for -N+1 <= k <= N-1
    for (auto k : diag2) {
        forbidden += N - abs(k);
    }

    // Now, subtract the overlaps between rows, columns, and diagonals
    // Overlap between row and column: already counted in both, so subtract 1 for each piece
    forbidden -= M;

    // Overlap between row and diag1: if (a, b) is on row a and diag1 (a + b = k), then (a, k - a) is on row a and diag1
    // Similarly for other overlaps, we need to subtract the counts where positions are counted multiple times
    // To avoid double-counting, we need to find intersections between row/col and diag1/diag2, and between diag1 and diag2

    // Overlap between row and diag1: for each piece (a, b), (a, b) is on row a and diag1 (a + b)
    // But since each piece is already counted in both row and diag1, we need to subtract 1 for each piece
    forbidden -= M;

    // Overlap between column and diag1: similarly, subtract M
    forbidden -= M;

    // Overlap between row and diag2: subtract M
    forbidden -= M;

    // Overlap between column and diag2: subtract M
    forbidden -= M;

    // Overlap between diag1 and diag2: each piece is on both diag1 and diag2, so subtract M
    forbidden -= M;

    // Now, add back the positions that were subtracted too many times (inclusion-exclusion principle)
    // For each piece, it was subtracted 6 times (for the 6 pairwise overlaps), but it should have been subtracted 3 times (once for each condition beyond the first)
    // So add back 3 * M
    forbidden += 3 * M;

    // Additionally, some positions might be forbidden by multiple pieces (but since pieces are unique, this doesn't affect the count)

    // Finally, the answer is N^2 - forbidden, but we must ensure that the pieces' original positions are not counted as forbidden (since they are already occupied)
    // The original pieces are part of the forbidden count, but they are not empty, so they should not be subtracted from the safe positions
    // Therefore, the number of safe positions is N^2 - forbidden + M (since forbidden includes M original positions that are already occupied)
    i64 answer = N * N - forbidden + M;

    // However, we must also ensure that the original pieces are not counted in the forbidden positions (since they are already occupied)
    // This is already handled by the inclusion-exclusion adjustments above

    cout << answer << "\n";

    return 0;
}