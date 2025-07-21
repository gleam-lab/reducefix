#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rows(H);
    vector<set<int>> cols(W);

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

        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
        } else {
            // Check up
            auto it_up = cols[C].lower_bound(R);
            if (it_up != cols[C].begin()) {
                --it_up;
                int i = *it_up;
                rows[i].erase(C);
                cols[C].erase(i);
            }

            // Check down
            auto it_down = cols[C].upper_bound(R);
            if (it_down != cols[C].end()) {
                int i = *it_down;
                rows[i].erase(C);
                cols[C].erase(i);
            }

            // Check left
            auto it_left = rows[R].lower_bound(C);
            if (it_left != rows[R].begin()) {
                --it_left;
                int j = *it_left;
                rows[R].erase(j);
                cols[j].erase(R);
            }

            // Check right
            auto it_right = rows[R].upper_bound(C);
            if (it_right != rows[R].end()) {
                int j = *it_right;
                rows[R].erase(j);
                cols[j].erase(R);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}