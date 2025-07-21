#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    rep(i, h) rep(j, w) {
        rows[i].insert(j);
        cols[j].insert(i);
    }
    int remaining = h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        } else {
            // Check up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int i = *it;
                rows[i].erase(c);
                cols[c].erase(it);
                remaining--;
            }
            // Check down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                int i = *it;
                rows[i].erase(c);
                cols[c].erase(it);
                remaining--;
            }
            // Check left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int j = *it;
                rows[r].erase(it);
                cols[j].erase(r);
                remaining--;
            }
            // Check right
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                int j = *it;
                rows[r].erase(it);
                cols[j].erase(r);
                remaining--;
            }
        }
    }
    cout << remaining << "\n";
    return 0;
}