#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H), col(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int remaining = H * W;
    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            --remaining;
        } else {
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                row[i].erase(c);
                col[c].erase(i);
                --remaining;
            }
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                row[i].erase(c);
                col[c].erase(i);
                --remaining;
            }
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                row[r].erase(j);
                col[j].erase(r);
                --remaining;
            }
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                row[r].erase(j);
                col[j].erase(r);
                --remaining;
            }
        }
    }
    cout << remaining << "\n";
    return 0;
}