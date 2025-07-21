#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // We'll use sets to keep track of walls in each row and column
    vector<set<int>> rows(H), cols(W);

    // Initialize with all walls present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at (R, C), destroy it and continue
        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
            continue;
        }

        // Otherwise, look in four directions
        vector<pair<int, int>> to_remove;

        // Up
        auto up = cols[C].lower_bound(R);
        if (up != cols[C].begin()) {
            --up;
            to_remove.emplace_back(*up, C);
            cols[C].erase(up);
            rows[*up].erase(C);
        }

        // Down
        auto down = cols[C].upper_bound(R);
        if (down != cols[C].end()) {
            to_remove.emplace_back(*down, C);
            cols[C].erase(down);
            rows[*down].erase(C);
        }

        // Left
        auto left = rows[R].lower_bound(C);
        if (left != rows[R].begin()) {
            --left;
            to_remove.emplace_back(R, *left);
            rows[R].erase(left);
            cols[*left].erase(R);
        }

        // Right
        auto right = rows[R].upper_bound(C);
        if (right != rows[R].end()) {
            to_remove.emplace_back(R, *right);
            rows[R].erase(right);
            cols[*right].erase(R);
        }
    }

    // Count remaining walls
    long long result = 0;
    for (int i = 0; i < H; ++i) {
        result += rows[i].size();
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}