#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Set to store the occupied cells
    set<pair<long long, long long>> occupied;
    // Set to store unique regions affected by the pieces
    set<pair<long long, long long>> affected;

    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;

        // Check all possible capturing moves and add them to the set
        occupied.insert({a, b});
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2}, {a - 1, b + 2},
            {a - 2, b + 1}, {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (auto& move : moves) {
            if (move.first < n && move.second < n && move.first >= 0 && move.second >= 0) {
                // Only add the move if it's within the grid bounds
                occupied.insert(move);
            }
        }
    }

    // Iterate through all occupied cells and determine the unique affected regions
    for (auto& cell : occupied) {
        long long x = cell.first, y = cell.second;
        vector<pair<long long, long long>> moves = {
            {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2},
            {x - 2, y + 1}, {x - 2, y - 1}, {x - 1, y - 2},
            {x + 1, y - 2}, {x + 2, y - 1}
        };

        for (auto& move : moves) {
            if (move.first < n && move.second < n && move.first >= 0 && move.second >= 0) {
                affected.insert(move);
            }
        }
    }

    // Calculate the number of cells that are not affected by any piece
    long long all_cells = n * n;
    long long captured_cells = occupied.size();
    long long free_cells = all_cells - affected.size() + captured_cells;
    cout << free_cells << endl;
}