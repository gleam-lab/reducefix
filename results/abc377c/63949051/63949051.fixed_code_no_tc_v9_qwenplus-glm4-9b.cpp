#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Create a bitmask of size N*N to represent the grid
    bitset<1000000000> grid;

    // Mark the squares that can be attacked by each piece
    for (auto& piece : pieces) {
        long long x = piece.first;
        long long y = piece.second;

        // Directions the piece can attack
        vector<pair<long long, long long>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        // Check each direction
        for (auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;

            // Check if the new position is within bounds
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                grid.set((nx - 1) * N + (ny - 1));
            }
        }
    }

    // Calculate the number of empty squares
    long long empty_squares = N * N;
    empty_squares -= grid.count();

    cout << empty_squares << endl;

    return 0;
}