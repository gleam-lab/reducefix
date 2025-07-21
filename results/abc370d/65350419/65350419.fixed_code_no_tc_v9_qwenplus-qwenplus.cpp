#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // For each column, keep track of remaining walls in that column (sorted)
    vector<set<int>> colWalls(W);
    // For each row, keep track of remaining walls in that row (sorted)
    vector<set<int>> rowWalls(H);

    // Initialize all walls present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            colWalls[j].insert(i);
            rowWalls[i].insert(j);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at the given cell
        auto it = rowWalls[r].find(c);
        if (it != rowWalls[r].end()) {
            // Wall exists, destroy it
            rowWalls[r].erase(it);
            colWalls[c].erase(colWalls[c].find(r));
        } else {
            // No wall at position, destroy first walls in each direction

            // Up
            auto upIt = colWalls[c].lower_bound(r);
            if (upIt != colWalls[c].begin()) {
                upIt--;
                int upRow = *upIt;
                rowWalls[upRow].erase(c);
                colWalls[c].erase(upIt);
            }

            // Down
            auto downIt = colWalls[c].lower_bound(r);
            if (downIt != colWalls[c].end()) {
                int downRow = *downIt;
                rowWalls[downRow].erase(c);
                colWalls[c].erase(downIt);
            }

            // Left
            auto leftIt = rowWalls[r].lower_bound(c);
            if (leftIt != rowWalls[r].begin()) {
                leftIt--;
                int leftCol = *leftIt;
                colWalls[leftCol].erase(r);
                rowWalls[r].erase(leftIt);
            }

            // Right
            auto rightIt = rowWalls[r].lower_bound(c);
            if (rightIt != rowWalls[r].end()) {
                int rightCol = *rightIt;
                colWalls[rightCol].erase(r);
                rowWalls[r].erase(rightIt);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += rowWalls[i].size();
    }
    cout << ans << endl;

    return 0;
}