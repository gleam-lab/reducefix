#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(W + 1), col(H + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].find(c) == row[r].end()) {
            // No wall at the current position
            // Look in all 4 directions

            // Left
            auto it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                destroy(r, *it);
            }

            // Right
            it = row[r].lower_bound(c);
            if (it != row[r].end() && *it != c)
                destroy(r, *it);

            // Up
            auto jt = col[c].lower_bound(r);
            if (jt != col[c].begin()) {
                --jt;
                destroy(*jt, c);
            }

            // Down
            jt = col[c].lower_bound(r);
            if (jt != col[c].end() && *jt != r)
                destroy(*jt, c);
        } else {
            // Wall exists, destroy just that one
            destroy(r, c);
        }
    }

    ll remaining = 0;
    for (int i = 1; i <= H; ++i)
        remaining += row[i].size();

    cout << remaining << '\n';

    return 0;
}