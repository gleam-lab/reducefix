#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // Using hash sets to keep track of the indices of walls to be destroyed
    unordered_set<int> verticalWalls, horizontalWalls;
    
    // To store the total number of walls that were present initially
    int totalWalls = H * W;

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If the wall at (R, C) is destroyed, remove it from the respective sets
        if (horizontalWalls.find(C) != horizontalWalls.end()) {
            horizontalWalls.erase(C);
        }
        if (verticalWalls.find(R) != verticalWalls.end()) {
            verticalWalls.erase(R);
        }
        totalWalls -= 4; // For every query, we destroy four walls

        // Now we need to destroy the first vertical and horizontal walls around (R, C)
        // We need to find the first wall to the left and right of (R, C) in the horizontal set
        auto left = horizontalWalls.lower_bound(C);
        auto right = horizontalWalls.upper_bound(C);

        // Erase walls from (R, left) to (R, C) in the horizontal direction
        while (left != horizontalWalls.end() && *left <= C) {
            verticalWalls.erase(*left);
            totalWalls -= 2; // Erasing each horizontal wall affects two vertical walls
            left = horizontalWalls.erase(left); // Continue to the next wall
        }

        // Erase walls from (R, C) to (R, right-1) in the horizontal direction
        while (right != horizontalWalls.begin()) {
            --right; // Move right to the previous wall
            verticalWalls.erase(right);
            totalWalls -= 2;
        }

        // Now we need to find the first wall above and below of (R, C) in the vertical set
        left = verticalWalls.lower_bound(R);
        right = verticalWalls.upper_bound(R);

        // Erase walls from (C, left) to (C, R) in the vertical direction
        while (left != verticalWalls.end() && *left <= R) {
            horizontalWalls.erase(*left);
            totalWalls -= 2; // Erasing each vertical wall affects two horizontal walls
            left = verticalWalls.erase(left); // Continue to the next wall
        }

        // Erase walls from (C, R) to (C, right-1) in the vertical direction
        while (right != verticalWalls.begin()) {
            --right; // Move right to the previous wall
            horizontalWalls.erase(right);
            totalWalls -= 2;
        }
    }

    // Output the total number of walls left
    cout << totalWalls << endl;

    return 0;
}