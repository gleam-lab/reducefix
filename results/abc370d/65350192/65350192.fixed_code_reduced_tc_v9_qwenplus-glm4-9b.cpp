#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<bool> tate(h, false), yoko(w, false);
    int totalWalls = h * w;
    totalWalls -= q; // Subtract one wall for each query as they are destroyed

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[r] || yoko[c]) {
            // If there's already no wall at (r, c), the wall is destroyed
            totalWalls++;
            tate[r] = false;
            yoko[c] = false;
        } else {
            // Search for the next wall to destroy upwards and downwards
            int nextUp = -1, nextDown = -1;
            for (int i = r - 1; i >= 0; i--) {
                if (!tate[i]) {
                    nextUp = i;
                    break;
                }
            }
            for (int i = r + 1; i < h; i++) {
                if (!tate[i]) {
                    nextDown = i;
                    break;
                }
            }
            if (nextUp != -1) {
                tate[r] = false;
                totalWalls--;
            }
            if (nextDown != -1) {
                tate[r] = false;
                totalWalls--;
            }

            // Search for the next wall to destroy leftwards and rightwards
            int nextLeft = -1, nextRight = -1;
            for (int j = c - 1; j >= 0; j--) {
                if (!yoko[j]) {
                    nextLeft = j;
                    break;
                }
            }
            for (int j = c + 1; j < w; j++) {
                if (!yoko[j]) {
                    nextRight = j;
                    break;
                }
            }
            if (nextLeft != -1) {
                yoko[c] = false;
                totalWalls--;
            }
            if (nextRight != -1) {
                yoko[c] = false;
                totalWalls--;
            }
        }
    }

    cout << totalWalls << "\n";
    return 0;
}