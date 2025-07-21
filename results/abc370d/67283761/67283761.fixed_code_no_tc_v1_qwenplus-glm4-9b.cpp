#include <vector>
#include <iostream>
using namespace std;

void destroyWalls(vector<vector<int>>& rows, vector<vector<int>>& columns, int r, int c) {
    int H = rows.size();
    int W = columns[r].size();

    // Destroy walls in the row vertically
    for (int j = 0; j < W; ++j) {
        if (rows[r][j] == 1) {
            rows[r][j] = 0;
            break;
        }
    }

    // Destroy walls in the column horizontally
    for (int i = 0; i < H; ++i) {
        if (columns[i][c] == 1) {
            columns[i][c] = 0;
            break;
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> rows(H, vector<int>(W + 1, 1)); // walls in rows
    vector<vector<int>> columns(W, vector<int>(H + 1, 1)); // walls in columns

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (rows[r][c] == 1) {
            // If there's a wall at (r, c), destroy it and stop.
            rows[r][c] = 0;
            columns[r][c] = 0;
        } else {
            // Destroy walls around (r, c)
            destroyWalls(rows, columns, r, c);
        }
    }

    // Calculate the total number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        remainingWalls += accumulate(rows[i].begin(), rows[i].end(), 0);
    }
    for (int j = 0; j < W; ++j) {
        remainingWalls += accumulate(columns[j].begin(), columns[j].end(), 0);
    }

    cout << remainingWalls << endl;

    return 0;
}