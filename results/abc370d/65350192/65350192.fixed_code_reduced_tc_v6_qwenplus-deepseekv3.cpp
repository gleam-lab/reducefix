#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
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
            auto it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int tmp = *it;
                row[tmp].erase(c);
                col[c].erase(tmp);
            }

            it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                it--;
                int tmp = *it;
                row[tmp].erase(c);
                col[c].erase(tmp);
            }

            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int tmp = *it;
                row[r].erase(tmp);
                col[tmp].erase(r);
            }

            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                it--;
                int tmp = *it;
                row[r].erase(tmp);
                col[tmp].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, h) ans += row[i].size();
    cout << ans << endl;
    return 0;
}