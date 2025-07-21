#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Up
            auto up_it = tate[c].lower_bound(r);
            if (up_it != tate[c].begin()) {
                up_it--;
                int i = *up_it;
                tate[c].erase(i);
                yoko[i].erase(c);
            }
            // Down
            auto down_it = tate[c].lower_bound(r);
            if (down_it != tate[c].end()) {
                int i = *down_it;
                tate[c].erase(i);
                yoko[i].erase(c);
            }
            // Left
            auto left_it = yoko[r].lower_bound(c);
            if (left_it != yoko[r].begin()) {
                left_it--;
                int j = *left_it;
                yoko[r].erase(j);
                tate[j].erase(r);
            }
            // Right
            auto right_it = yoko[r].lower_bound(c);
            if (right_it != yoko[r].end()) {
                int j = *right_it;
                yoko[r].erase(j);
                tate[j].erase(r);
            }
        }
    }
    int ans = 0;
    rep(i, w) ans += tate[i].size();
    cout << ans << "\n";
    return 0;
}