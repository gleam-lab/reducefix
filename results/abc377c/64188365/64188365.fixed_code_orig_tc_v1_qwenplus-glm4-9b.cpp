#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    set<pair<long long, long long>> occupied;

    // Reading the positions of all existing pieces and marking them in the set
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        occupied.insert({pieces[i].first, pieces[i].second});
    }

    long long emptyCount = 0;

    // Iterate through all possible positions on the grid
    for (long long row = 1; row <= n; ++row) {
        for (long long col = 1; col <= n; ++col) {
            bool canPlace = true;

            // Check if the current position is an empty square and is not under attack by any piece
            for (const auto& piece : pieces) {
                if (occupied.count({piece.first, piece.second})) continue;

                // Check if the position is within the capturing range of the piece
                if ((row == piece.first + 2 && col == piece.second + 1) ||
                    (row == piece.first + 1 && col == piece.second + 2) ||
                    (row == piece.first + 1 && col == piece.second - 2) ||
                    (row == piece.first - 1 && col == piece.second + 2) ||
                    (row == piece.first - 2 && col == piece.second + 1) ||
                    (row == piece.first - 2 && col == piece.second - 1) ||
                    (row == piece.first - 1 && col == piece.second - 2) ||
                    (row == piece.first + 2 && col == piece.second - 1)) {
                    canPlace = false;
                    break;
                }
            }

            // If the current position is not attacked by any piece, count it as an empty square
            if (canPlace) {
                emptyCount++;
            }
        }
    }

    cout << emptyCount << endl;

    return 0;
}