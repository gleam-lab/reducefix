#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<map<int, bool>> rowWalls(H), colWalls(W);
    int totalWalls = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (rowWalls[R].find(C) == rowWalls[R].end()) {
            // No wall at (R, C), look in four directions
            // Up
            auto it = rowWalls[R].lower_bound(C);
            if (it != rowWalls[R].begin()) {
                it--;
                totalWalls--;
                rowWalls[R].erase(it);
            }

            // Down
            it = rowWalls[R].upper_bound(C);
            if (it != rowWalls[R].end()) {
                totalWalls--;
                rowWalls[R].erase(it);
            }

            // Left
            auto &colMap = colWalls[C];
            auto jt = colMap.lower_bound(R);
            if (jt != colMap.begin()) {
                jt--;
                totalWalls--;
                colMap.erase(jt);
            }

            // Right
            jt = colMap.upper_bound(R);
            if (jt != colMap.end()) {
                totalWalls--;
                colMap.erase(jt);
            }
        } else {
            // Wall exists, just remove it
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            totalWalls--;
        }
    }

    cout << totalWalls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}