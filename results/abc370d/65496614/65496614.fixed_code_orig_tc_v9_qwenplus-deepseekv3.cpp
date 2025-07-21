#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rows(H + 2);
    vector<set<int>> cols(W + 2);

    for (int i = 1; i <= H; ++i) {
        rows[i].insert(0);
        rows[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        cols[j].insert(0);
        cols[j].insert(H + 1);
    }

    int remaining = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (rows[R].count(C) == 0) {
            // The cell has no wall, find adjacent walls
            auto it = rows[R].lower_bound(C);
            int right = *it;
            --it;
            int left = *it;

            if (left + 1 <= C - 1 && cols[C - 1].count(R)) {
                cols[C - 1].erase(R);
                --remaining;
            }
            if (C + 1 <= right - 1 && cols[C + 1].count(R)) {
                cols[C + 1].erase(R);
                --remaining;
            }

            it = cols[C].lower_bound(R);
            int down = *it;
            --it;
            int up = *it;

            if (up + 1 <= R - 1 && rows[R - 1].count(C)) {
                rows[R - 1].erase(C);
                --remaining;
            }
            if (R + 1 <= down - 1 && rows[R + 1].count(C)) {
                rows[R + 1].erase(C);
                --remaining;
            }
        } else {
            // The cell has a wall, remove it
            rows[R].erase(C);
            cols[C].erase(R);
            --remaining;
        }
    }

    cout << remaining << '\n';
    return 0;
}