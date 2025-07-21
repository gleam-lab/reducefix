#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H + 2);
    vector<set<int>> col(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int ans = H * W;
    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            --ans;
        } else {
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                int r = *it_up;
                if (row[r].count(C)) {
                    row[r].erase(C);
                    col[C].erase(r);
                    --ans;
                }
            }

            // Down
            auto it_down = col[C].lower_bound(R);
            if (it_down != col[C].end()) {
                int r = *it_down;
                if (row[r].count(C)) {
                    row[r].erase(C);
                    col[C].erase(r);
                    --ans;
                }
            }

            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                int c = *it_left;
                if (col[c].count(R)) {
                    col[c].erase(R);
                    row[R].erase(c);
                    --ans;
                }
            }

            // Right
            auto it_right = row[R].lower_bound(C);
            if (it_right != row[R].end()) {
                int c = *it_right;
                if (col[c].count(R)) {
                    col[c].erase(R);
                    row[R].erase(c);
                    --ans;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}