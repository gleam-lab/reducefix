#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    // Set to store coordinates of existing pieces
    set<pair<long long, long long>> pieces;

    // Read the positions of existing pieces
    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    // Directions in which a piece can capture another piece
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to store coordinates of cells that can be captured
    set<pair<long long, long long>> unsafe_cells;

    // Mark cells that can be captured
    for (const auto& [x, y] : pieces) {
        for (const auto& [dx, dy] : directions) {
            long long nx = x + dx;
            long long ny = y + dy;
            if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                unsafe_cells.insert({nx, ny});
            }
        }
    }

    // Calculate the number of safe cells
    long long safe_cells = N * N - unsafe_cells.size();

    cout << safe_cells << endl;

    return 0;
}