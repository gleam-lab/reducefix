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

    int ans = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            ans--;
        } else {
            // Up
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                --it;
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
                ans--;
            }

            // Down
            it = col[C].lower_bound(R);
            if (it != col[C].end()) {
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
                ans--;
            }

            // Left
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                --it;
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
                ans--;
            }

            // Right
            it = row[R].lower_bound(C);
            if (it != row[R].end()) {
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}