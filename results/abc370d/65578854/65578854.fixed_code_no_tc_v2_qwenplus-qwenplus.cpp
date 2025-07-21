#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row, we maintain a set of columns that still have walls
    vector<set<int>> rowWalls(H);
    // For each column, we maintain a set of rows that still have walls
    vector<set<int>> colWalls(W);

    // Initialize all walls present
    rep(i, H) rep(j, W) {
        rowWalls[i].insert(j);
        colWalls[j].insert(i);
    }

    ll remainingWalls = (ll)H * W;

    auto destroyWall = [&](int r, int c) {
        if (rowWalls[r].count(c)) {
            remainingWalls--;
            rowWalls[r].erase(c);
            colWalls[c].erase(r);
        }
    };

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at the current cell, destroy it and continue
        if (!rowWalls[R].count(C)) {
            // No wall at this position, need to look in four directions
            // Up
            auto it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].begin()) {
                it--;
                int up = *it;
                destroyWall(up, C);
            }

            // Down
            it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].end() && *it != R) {
                int down = *it;
                destroyWall(down, C);
            }

            // Left
            auto jt = rowWalls[R].lower_bound(C);
            if (jt != rowWalls[R].begin()) {
                jt--;
                int left = *jt;
                destroyWall(R, left);
            }

            // Right
            jt = rowWalls[R].lower_bound(C);
            if (jt != rowWalls[R].end() && *jt != C) {
                int right = *jt;
                destroyWall(R, right);
            }
        } else {
            // Destroy the wall at (R, C)
            destroyWall(R, C);
        }
    }

    cout << remainingWalls << endl;
    return 0;
}