#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> col(w), row(h);
    rep(i, h) rep(j, w) {
        col[j].insert(i);
        row[i].insert(j);
    }
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (col[c].count(r)) {
            col[c].erase(r);
            row[r].erase(c);
        } else {
            // Up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int tmp = *it;
                col[c].erase(tmp);
                row[tmp].erase(c);
            }
            // Down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int tmp = *it;
                col[c].erase(tmp);
                row[tmp].erase(c);
            }
            // Left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int tmp = *it;
                row[r].erase(tmp);
                col[tmp].erase(r);
            }
            // Right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int tmp = *it;
                row[r].erase(tmp);
                col[tmp].erase(r);
            }
        }
    }
    int ans = 0;
    rep(i, w) ans += col[i].size();
    cout << ans << "\n";
    return 0;
}