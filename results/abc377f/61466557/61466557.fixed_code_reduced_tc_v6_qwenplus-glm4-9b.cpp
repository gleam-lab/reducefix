#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Directions for diagonals: (row - col, row + col)
    // These correspond to the diagonal increments
    set<pair<long long, long long>> directions;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        // Subtract 1 because input is 1-based, and we need 0-based for indexing
        directions.insert({a - 1, b - 1});
        directions.insert({a - 1, -(b - 1)});
        directions.insert({-(a - 1), b - 1});
        directions.insert({-(a - 1), -(b - 1)});
    }

    // Calculate the number of empty cells
    long long total_empty_cells = N * N;

    // Subtract cells from rows and columns
    for (long long i = 0; i < N; ++i) {
        total_empty_cells -= 1;
    }
    for (long long j = 0; j < N; ++j) {
        total_empty_cells -= 1;
    }

    // Subtract cells that are on diagonals
    for (auto& dir : directions) {
        long long max_diagonal_length = min(dir.first, dir.second) + 1;
        total_empty_cells -= max_diagonal_length;
    }

    // Special case: subtract the main diagonals (where row = col)
    total_empty_cells -= 2;

    cout << total_empty_cells;
    return 0;
}