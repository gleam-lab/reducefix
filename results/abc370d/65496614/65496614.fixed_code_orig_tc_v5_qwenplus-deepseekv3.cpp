#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
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

    int remaining = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            remaining--;
        } else {
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                int i = *it_up;
                if (row[i].count(C)) {
                    row[i].erase(C);
                    col[C].erase(i);
                    remaining--;
                }
            }

            // Down
            auto it_down = col[C].lower_bound(R);
            if (it_down != col[C].end()) {
                int i = *it_down;
                if (row[i].count(C)) {
                    row[i].erase(C);
                    col[C].erase(i);
                    remaining--;
                }
            }

            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                int j = *it_left;
                if (col[j].count(R)) {
                    col[j].erase(R);
                    row[R].erase(j);
                    remaining--;
                }
            }

            // Right
            auto it_right = row[R].lower_bound(C);
            if (it_right != row[R].end()) {
                int j = *it_right;
                if (col[j].count(R)) {
                    col[j].erase(R);
                    row[R].erase(j);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << endl;

    return 0;
}