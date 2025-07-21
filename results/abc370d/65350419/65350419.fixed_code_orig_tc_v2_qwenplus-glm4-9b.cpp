#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<int> walls(h * w, 1); // walls[i * w + j] represents the number of walls at (i, j)

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int index = i * w + j;
            if (i > 0) {
                walls[index] += walls[index - w];
            }
            if (j > 0) {
                walls[index] += walls[index - 1];
                if (i > 0) {
                    walls[index] -= walls[index - w - 1];
                }
            }
        }
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        --r; --c; // convert to 0-based index
        int index = r * w + c;

        if (walls[index] == 1) {
            walls[index] = 0;
        } else {
            // Remove walls from left to right
            for (int j = c - 1; j >= 0; --j) {
                int upIndex = (r - 1) * w + j;
                int downIndex = (r + 1) * w + j;
                if (j > 0) {
                    walls[index - 1] -= walls[index - w - 1];
                }
                if (upIndex >= 0) {
                    walls[upIndex] -= walls[index - w];
                }
                if (downIndex < h * w) {
                    walls[downIndex] -= walls[index - w];
                }
                walls[index] += walls[index - 1];
                walls[index - 1] = 0;
                index--;
            }
            // Remove walls from top to bottom
            for (int i = r - 1; i >= 0; --i) {
                int leftIndex = i * w + c;
                int rightIndex = i * w + c + 1;
                if (i > 0) {
                    walls[leftIndex] -= walls[leftIndex - w];
                }
                if (c + 1 < w) {
                    walls[rightIndex] -= walls[rightIndex - w];
                }
                walls[i * w + c] += walls[i * w + c - 1];
                walls[i * w + c - 1] = 0;
                c--;
            }
        }
    }

    // Calculate the number of remaining walls
    ll remainingWalls = 0;
    for (int i = 0; i < h * w; i++) {
        remainingWalls += walls[i];
    }
    cout << remainingWalls << endl;
    return 0;
}