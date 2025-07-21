#include <queue>

// ... [rest of the header and initialization code]

for (int i = 1; i <= Y; i++) {
    bool newSunk = false; // flag to indicate if any new sections sink this year
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (island[x][y]) { // if the section is still above sea level
                bool shouldSink = false;
                for (int d = 0; d < 4; d++) { // check neighbors
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= H || ny >= W || !island[nx][ny]) {
                        continue; // is a border or already sunk
                    }
                    if (A[nx][ny] + i > A[x][y]) { // the neighbor is above the new sea level
                        shouldSink = true;
                        break;
                    }
                }
                if (shouldSink) {
                    island[x][y] = false; // sink this section
                    newSunk = true;
                }
            }
        }
    }
    if (newSunk) { // if any sections have sunk, we need to re-run the checking process
        // ... [re-run the propagation logic for neighbor sinking]
    }
    // ... [update area calculation and output]
}