#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H + 2), col(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int cnt = 0;
    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            ++cnt;
        } else {
            // Up
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                --it;
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
                ++cnt;
            }
            // Down
            it = col[C].lower_bound(R);
            if (it != col[C].end()) {
                int r = *it;
                row[r].erase(C);
                col[C].erase(r);
                ++cnt;
            }
            // Left
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                --it;
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
                ++cnt;
            }
            // Right
            it = row[R].lower_bound(C);
            if (it != row[R].end()) {
                int c = *it;
                row[R].erase(c);
                col[c].erase(R);
                ++cnt;
            }
        }
    }

    cout << H * W - cnt << endl;
    return 0;
}