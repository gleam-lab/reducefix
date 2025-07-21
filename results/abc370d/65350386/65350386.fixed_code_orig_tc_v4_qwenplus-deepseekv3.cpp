#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    int ans = h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
        } else {
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                it_up--;
                int i = *it_up;
                row[i].erase(c);
                col[c].erase(it_up);
                ans--;
            }
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                int i = *it_down;
                row[i].erase(c);
                col[c].erase(it_down);
                ans--;
            }
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                it_left--;
                int j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
                ans--;
            }
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                int j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
                ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}