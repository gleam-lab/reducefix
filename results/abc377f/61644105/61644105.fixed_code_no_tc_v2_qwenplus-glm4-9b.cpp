#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces;
    pieces.reserve(m);

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
    }

    sort(pieces.begin(), pieces.end());

    long long availableSquares = n * n;

    // Rows and columns taken by any piece
    vector<long long> rows(n + 1), cols(n + 1), diag1(2 * n + 1), diag2(2 * n + 1);

    // Mark rows, columns, and diagonals occupied by pieces
    for (const auto& p : pieces) {
        rows[p.first] = 1;
        cols[p.second] = 1;
        diag1[p.first + p.second - 1] = 1;
        diag2[p.first - p.second + n - 1] = 1;
    }

    // Count the number of occupied squares in rows, columns, and diagonals
    for (long long i = 1; i <= n; ++i) {
        if (rows[i]) availableSquares--;
        if (cols[i]) availableSquares--;
        if (diag1[i]) availableSquares--;
        if (diag2[i]) availableSquares--;
    }

    // Output the number of available squares
    cout << availableSquares << endl;

    return 0;
}