#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> st1(H + 1), st2(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            st1[i].insert(j);
            st2[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        // Check if a wall exists at (r, c)
        if (st1[r].find(c) == st1[r].end() && st2[c].find(r) == st2[c].end()) {
            // No wall at (r, c), remove walls from surrounding cells
            // Remove the first wall in the row above (r, c)
            if (!st1[r-1].empty()) {
                st1[r-1].erase(st1[r-1].begin());
            }
            // Remove the first wall in the row below (r, c)
            if (!st1[r+1].empty()) {
                st1[r+1].erase(st1[r+1].begin());
            }
            // Remove the first wall in the column to the left of (r, c)
            if (!st2[c-1].empty()) {
                st2[c-1].erase(st2[c-1].begin());
            }
            // Remove the first wall in the column to the right of (r, c)
            if (!st2[c+1].empty()) {
                st2[c+1].erase(st2[c+1].begin());
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= H; ++i) {
        remainingWalls += st1[i].size();
    }
    for (int j = 1; j <= W; ++j) {
        remainingWalls += st2[j].size();
    }

    cout << remainingWalls << endl;

    return 0;
}