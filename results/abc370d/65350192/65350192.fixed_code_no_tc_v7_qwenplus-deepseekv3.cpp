#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                row[i].erase(c);
                col[c].erase(it);
            }
            // Down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                row[i].erase(c);
                col[c].erase(it);
            }
            // Left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                row[r].erase(it);
                col[j].erase(r);
            }
            // Right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                row[r].erase(it);
                col[j].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, h) ans += row[i].size();
    cout << ans << '\n';

    return 0;
}