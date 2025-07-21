#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h + 2);
    vector<set<int>> col(w + 2);

    for (int i = 1; i <= h; ++i) {
        row[i].insert(0);
        row[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        col[j].insert(0);
        col[j].insert(h + 1);
    }

    vector<vector<bool>> coo(h + 2, vector<bool>(w + 2, true));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (coo[r][c]) {
            coo[r][c] = false;
            row[r].erase(c);
            col[c].erase(r);
        } else {
            auto it = row[r].lower_bound(c);
            int right = *it;
            --it;
            int left = *it;
            if (left >= 1 && coo[r][left]) {
                coo[r][left] = false;
                row[r].erase(left);
                col[left].erase(r);
            }
            if (right <= w && coo[r][right]) {
                coo[r][right] = false;
                row[r].erase(right);
                col[right].erase(r);
            }

            it = col[c].lower_bound(r);
            int down = *it;
            --it;
            int up = *it;
            if (up >= 1 && coo[up][c]) {
                coo[up][c] = false;
                row[up].erase(c);
                col[c].erase(up);
            }
            if (down <= h && coo[down][c]) {
                coo[down][c] = false;
                row[down].erase(c);
                col[c].erase(down);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += coo[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}