#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rowWalls(h), colWalls(w);

    // Initialize wall positions on the grid boundaries
    for (int i = 0; i < h; ++i) {
        rowWalls[i].insert(0);
        rowWalls[i].insert(w - 1);
    }
    for (int j = 0; j < w; ++j) {
        colWalls[j].insert(0);
        colWalls[j].insert(h - 1);
    }

    // Process all queries
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index
        
        // Check if there's a wall at the position
        if (rowWalls[r].find(c) != rowWalls[r].end()) {
            rowWalls[r].erase(c);
        } else if (colWalls[c].find(r) != colWalls[c].end()) {
            colWalls[c].erase(r);
        } else {
            // No wall exists, remove all walls in the four directions
            for (int j = 0; j < w; ++j) {
                if (j != c && rowWalls[r].find(j) != rowWalls[r].end()) {
                    rowWalls[r].erase(j);
                }
            }
            for (int i = 0; i < h; ++i) {
                if (i != r && colWalls[c].find(i) != colWalls[c].end()) {
                    colWalls[c].erase(i);
                }
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (const auto &row : rowWalls) {
        remainingWalls += row.size();
    }
    for (const auto &col : colWalls) {
        remainingWalls += col.size();
    }

    cout << remainingWalls << endl;
    return 0;
}