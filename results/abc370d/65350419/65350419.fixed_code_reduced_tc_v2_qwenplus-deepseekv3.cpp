#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> cols(w), rows(h);
    rep(i,h) rep(j,w) {
        cols[j].insert(i);
        rows[i].insert(j);
    }
    int total = h * w;
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (cols[c].count(r)) {
            cols[c].erase(r);
            rows[r].erase(c);
            total--;
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int tmp = *it;
                if (cols[c].count(tmp)) {
                    cols[c].erase(tmp);
                    rows[tmp].erase(c);
                    total--;
                }
            }
            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                int tmp = *it;
                if (cols[c].count(tmp)) {
                    cols[c].erase(tmp);
                    rows[tmp].erase(c);
                    total--;
                }
            }
            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int tmp = *it;
                if (rows[r].count(tmp)) {
                    rows[r].erase(tmp);
                    cols[tmp].erase(r);
                    total--;
                }
            }
            // Right
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                int tmp = *it;
                if (rows[r].count(tmp)) {
                    rows[r].erase(tmp);
                    cols[tmp].erase(r);
                    total--;
                }
            }
        }
    }
    cout << total << "\n";
    return 0;
}