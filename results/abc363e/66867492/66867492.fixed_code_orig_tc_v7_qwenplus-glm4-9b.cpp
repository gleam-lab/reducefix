#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // To keep track of the areas that are still above sea level
    set<pair<int, int>> aboveSeaLevel;

    // Initialize the set with the boundaries of the island
    for (int i = 0; i < H; ++i) {
        aboveSeaLevel.emplace(i, 0);
        aboveSeaLevel.emplace(i, W - 1);
    }
    for (int j = 0; j < W; ++j) {
        aboveSeaLevel.emplace(0, j);
        aboveSeaLevel.emplace(H - 1, j);
    }

    // To keep track of the current sea level
    int currentSeaLevel = 0;

    // Process each year
    for (int year = 0; year < Y; ++year) {
        set<pair<int, int>> newAboveSeaLevel;

        // Check each cell in the island
        for (int i = 1; i < H - 1; ++i) {
            for (int j = 1; j < W - 1; ++j) {
                int neighborsSunk = 0;
                // Check all four neighbors
                if (A[i - 1][j] <= currentSeaLevel) neighborsSunk++;
                if (A[i + 1][j] <= currentSeaLevel) neighborsSunk++;
                if (A[i][j - 1] <= currentSeaLevel) neighborsSunk++;
                if (A[i][j + 1] <= currentSeaLevel) neighborsSunk++;

                // If three or more neighbors are sunk, this cell will sink
                if (neighborsSunk >= 3) {
                    // Do not add to newAboveSeaLevel
                } else {
                    // Otherwise, add to newAboveSeaLevel
                    newAboveSeaLevel.emplace(i, j);
                }
            }
        }

        // Update the set of above sea level areas
        aboveSeaLevel = move(newAboveSeaLevel);

        // Increment the sea level
        currentSeaLevel++;

        // Output the number of areas above sea level
        cout << aboveSeaLevel.size() << '\n';
    }

    return 0;
}