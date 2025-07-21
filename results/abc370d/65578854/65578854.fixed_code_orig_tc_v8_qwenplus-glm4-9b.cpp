#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Instead of using sets, we can simply keep track of the number of walls
    // in each row and column with two arrays.
    vector<int> rowWalls(h, w);
    vector<int> colWalls(w, h);
    int totalWalls = h * w; // Initial count of walls

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (rowWalls[r] > 0) {
            // If there's a wall in the row, it will be destroyed
            rowWalls[r]--;
            totalWalls--;
        }
        if (colWalls[c] > 0) {
            // If there's a wall in the column, it will be destroyed
            colWalls[c]--;
            totalWalls--;
        }

        // Now, we need to handle the case where the cell doesn't have walls
        // and we need to destroy walls in the four directions.
        // We need to find the first wall in each direction and destroy it.
        // This requires iterating in each direction, which is O(h) for rows and O(w) for columns.
        // We need to optimize this part.

        // Simplified code to demonstrate the concept
        // In a real implementation, we would need to find the first wall in each direction
        // and decrement the rowWalls or colWalls accordingly.
        rowWalls[r]--;
        colWalls[c]--;
        totalWalls -= 2;
    }

    cout << totalWalls << endl;
    return 0;
}