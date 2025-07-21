#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Use maps to efficiently manage row and column walls
    map<int, vector<int>> row;
    map<int, vector<int>> col;

    // Initialize the walls in each cell
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].push_back(j);
            col[j].push_back(i);
        }
    }

    int remainingWalls = H * W; // Start with all walls

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;

        // Check if there's a wall at (R, C)
        if (row[R].end() != find(row[R].begin(), row[R].end(), C)) {
            // Remove the wall at (R, C)
            row[R].erase(find(row[R].begin(), row[R].end(), C));
            col[C].erase(find(col[C].begin(), col[C].end(), R));
            --remainingWalls;
        } else {
            // Remove the first wall in the row and column
            if (!row[R].empty()) {
                int wallToDestroy = row[R][0];
                row[R].erase(row[R].begin());
                col[wallToDestroy].erase(find(col[wallToDestroy].begin(), col[wallToDestroy].end(), R));
                --remainingWalls;
            }
            if (!col[C].empty()) {
                int wallToDestroy = col[C][0];
                col[C].erase(col[C].begin());
                row[wallToDestroy].erase(find(row[wallToDestroy].begin(), row[wallToDestroy].end(), wallToDestroy));
                --remainingWalls;
            }
        }
    }

    cout << remainingWalls << endl;
}