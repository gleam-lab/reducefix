#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Count the number of rows, columns, and diagonals that are "captured"
    int capturedRows = 0, capturedCols = 0, capturedDiags = 0, capturedAntiDiags = 0;
    vector<int> rowCaptures(n + 1, 0), colCaptures(n + 1, 0);

    for (const auto& p : pieces) {
        rowCaptures[p.first]++;
        colCaptures[p.second]++;
        capturedDiags++;
        capturedAntiDiags++;
        capturedDiags += (p.first - p.second <= n);
        capturedAntiDiags += (p.first + p.second <= n);
    }

    // If one row or one column is fully captured, then all the empty positions in that row or column
    // are captured because there is no way to place a piece there that would not be captured.
    for (int row : rowCaptures) {
        if (row == n) capturedRows++;
    }
    for (int col : colCaptures) {
        if (col == n) capturedCols++;
    }

    // Total number of captured positions is the sum of captured rows, columns, diagonals, and antidiagonals.
    long long capturedPositions = capturedRows + capturedCols + capturedDiags + capturedAntiDiags;

    // Total number of squares is n * n.
    long long totalSquares = n * n;

    // Calculate the number of empty squares where you can place your piece.
    // Subtract captured positions from total squares.
    // Add n because we need to account for the first row, first column, first diagonal, and first antidiagonal.
    long long result = totalSquares - capturedPositions + n;

    // Output the result modulo MOD.
    cout << result % MOD << '\n';

    return 0;
}