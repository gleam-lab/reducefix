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
            auto it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                int j = *prev(it);
                if (row[r].count(j)) {
                    row[r].erase(j);
                    col[j].erase(r);
                    ans--;
                }
            }
            it = row[r].upper_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                if (row[r].count(j)) {
                    row[r].erase(j);
                    col[j].erase(r);
                    ans--;
                }
            }
            it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                int i = *prev(it);
                if (col[c].count(i)) {
                    col[c].erase(i);
                    row[i].erase(c);
                    ans--;
                }
            }
            it = col[c].upper_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                if (col[c].count(i)) {
                    col[c].erase(i);
                    row[i].erase(c);
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}