#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, maintain a set of remaining wall positions
    vector<set<int>> rows(H), cols(W);

    // Initialize all walls present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check if there's a wall at (R, C)
        if (rows[R].count(C)) {
            // Destroy the wall at (R, C)
            rows[R].erase(C);
            cols[C].erase(R);
        } else {
            // Destroy the first wall in each direction

            // Up
            auto it = cols[C].lower_bound(R);
            if (it != cols[C].begin()) {
                it--;
                int r = *it;
                rows[r].erase(C);
                cols[C].erase(r);
            }

            // Down
            it = cols[C].lower_bound(R);
            if (it != cols[C].end()) {
                int r = *it;
                rows[r].erase(C);
                cols[C].erase(r);
            }

            // Left
            auto jt = rows[R].lower_bound(C);
            if (jt != rows[R].begin()) {
                jt--;
                int c = *jt;
                cols[c].erase(R);
                rows[R].erase(c);
            }

            // Right
            jt = rows[R].lower_bound(C);
            if (jt != rows[R].end()) {
                int c = *jt;
                cols[c].erase(R);
                rows[R].erase(c);
            }
        }
    }

    // Count remaining walls
    long long result = 0;
    for (int i = 0; i < W; ++i) {
        result += cols[i].size();
    }

    cout << result << endl;

    return 0;
}