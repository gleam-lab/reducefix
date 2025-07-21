#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<bool> rowWall(h, true), colWall(w, true);
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (colWall[c]) {
            colWall[c] = false;
            for (int i = 0; i < h; ++i) {
                rowWall[i] = false;
            }
        } else {
            // Remove wall at (r, c)
            rowWall[r] = false;
            colWall[c] = false;
            
            // Remove vertical walls
            for (int i = 0; i < w; ++i) {
                if (colWall[i]) {
                    bool first = true;
                    for (int j = 0; j < h; ++j) {
                        if (rowWall[j]) {
                            if (first) {
                                colWall[i] = false;
                                first = false;
                            }
                            rowWall[j] = false;
                        }
                    }
                    if (!first) {
                        break;
                    }
                }
            }
            
            // Remove horizontal walls
            for (int i = 0; i < h; ++i) {
                if (rowWall[i]) {
                    bool first = true;
                    for (int j = 0; j < w; ++j) {
                        if (colWall[j]) {
                            if (first) {
                                rowWall[i] = false;
                                first = false;
                            }
                            colWall[j] = false;
                        }
                    }
                    if (!first) {
                        break;
                    }
                }
            }
        }
    }
    
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (rowWall[i] || colWall[j]) {
                remainingWalls++;
            }
        }
    }
    
    cout << remainingWalls << endl;
    return 0;
}