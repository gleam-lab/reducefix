#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<int> rows(h * w, 0), cols(w, 0);
    rep(i, h) rep(j, w) {
        rows[i * w + j] = 1; // Initialize all walls in row i and column j
        cols[j] = 1; // Initialize all walls in column j
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (rows[r * w + c] == 1) {
            // If there is a wall at (r, c), destroy it
            rows[r * w + c] = 0;
            cols[c]--;
        } else {
            // If there is no wall at (r, c), destroy walls in row r and column c
            rep(i, h) {
                if (rows[i * w + c] == 1) {
                    rows[i * w + c] = 0;
                    cols[c]--;
                }
            }
            rep(j, w) {
                if (cols[j] == 1) { // Only destroy rows with walls
                    for (int k = 0; k < h; k++) {
                        if (rows[k * w + j] == 1) {
                            rows[k * w + j] = 0;
                        }
                    }
                    cols[j]--;
                }
            }
        }
    }
    
    // Calculate the number of remaining walls
    int remainingWalls = 0;
    rep(i, h) {
        rep(j, w) {
            if (rows[i * w + j] == 1 || cols[j] == 1) {
                remainingWalls++;
            }
        }
    }
    cout << remainingWalls << endl;
    return 0;
}