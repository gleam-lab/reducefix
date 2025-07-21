#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<map<int, bool>> row(H), col(W);
    int total_destroyed = 0;

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (row[R].find(C) == row[R].end()) {
            // No wall at (R, C), need to destroy walls in four directions
            // Check up
            int destroyed = 0;
            // Up
            for (int i = R - 1; i >= 0; --i) {
                if (row[i].find(C) != row[i].end()) {
                    row[i].erase(C);
                    col[C].erase(i);
                    total_destroyed++;
                    break;
                }
            }
            // Down
            for (int i = R + 1; i < H; ++i) {
                if (row[i].find(C) != row[i].end()) {
                    row[i].erase(C);
                    col[C].erase(i);
                    total_destroyed++;
                    break;
                }
            }
            // Left
            for (int j = C - 1; j >= 0; --j) {
                if (row[R].find(j) != row[R].end()) {
                    row[R].erase(j);
                    col[j].erase(R);
                    total_destroyed++;
                    break;
                }
            }
            // Right
            for (int j = C + 1; j < W; ++j) {
                if (row[R].find(j) != row[R].end()) {
                    row[R].erase(j);
                    col[j].erase(R);
                    total_destroyed++;
                    break;
                }
            }
        } else {
            // Destroy the wall at (R, C)
            row[R].erase(C);
            col[C].erase(R);
            total_destroyed++;
        }
    }

    long long total_cells = 1LL * H * W;
    cout << (total_cells - total_destroyed) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}