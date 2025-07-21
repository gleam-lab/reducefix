#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Use sets to track threatened rows, columns, and diagonals
    unordered_set<int> threatened_rows, threatened_cols;
    unordered_set<pair<int, int>, pair_hash> threatened_diag1, threatened_diag2;

    for (long long i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        // Convert 1-based index to 0-based
        --a, --b;

        threatened_rows.insert(a);
        threatened_cols.insert(b);

        // Calculate diagonals for capture conditions
        int diag1 = a + b;
        int diag2 = a - b;
        threatened_diag1.insert({diag1, b});
        threatened_diag2.insert({diag2, b});
    }

    // Calculate the number of empty squares
    long long empty_squares = n * n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Check if the square is threatened by row or column
            if (threatened_rows.count(i) || threatened_cols.count(j)) {
                empty_squares--;
            }
            // Check if the square is threatened by diagonal
            int diag1 = i + j;
            int diag2 = i - j;
            if (threatened_diag1.count({diag1, j}) || threatened_diag2.count({diag2, j})) {
                empty_squares--;
            }
        }
    }

    cout << empty_squares << endl;
    return 0;
}