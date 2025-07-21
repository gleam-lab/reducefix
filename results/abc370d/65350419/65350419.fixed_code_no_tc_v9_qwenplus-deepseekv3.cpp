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

    ll remaining = (ll)h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        } else {
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                int pos = *it_up;
                row[pos].erase(c);
                col[c].erase(pos);
                remaining--;
            }
            // Down
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                int pos = *it_down;
                row[pos].erase(c);
                col[c].erase(pos);
                remaining--;
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                int pos = *it_left;
                row[r].erase(pos);
                col[pos].erase(r);
                remaining--;
            }
            // Right
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                int pos = *it_right;
                row[r].erase(pos);
                col[pos].erase(r);
                remaining--;
            }
        }
    }
    cout << remaining << "\n";
    return 0;
}