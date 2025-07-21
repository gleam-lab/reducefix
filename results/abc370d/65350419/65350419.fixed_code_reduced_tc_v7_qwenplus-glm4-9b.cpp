#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<set<int>>> tate(w, vector<set<int>>(h));
    vector<vector<set<int>>> yoko(h, vector<set<int>>(w));
    int totalWalls = h * w; // Start with all walls counted

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tate[j][i].insert(i);
            yoko[i][j].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (tate[c][r].empty()) {
            // No wall at (r, c), so we need to remove walls in all four directions
            for (int i = 0; i < h; i++) {
                if (i != r && !yoko[i][c].empty()) {
                    yoko[i][c].erase(c);
                    totalWalls--;
                }
            }
            for (int j = 0; j < w; j++) {
                if (j != c && !tate[j][r].empty()) {
                    tate[j][r].erase(r);
                    totalWalls--;
                }
            }
        } else {
            // Wall at (r, c) exists, remove it
            tate[c][r].erase(r);
            yoko[r][c].erase(c);
            totalWalls--;
        }
    }

    cout << totalWalls << endl;
    return 0;
}