#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
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
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].begin()) {
                --it;
                int tmp = *it;
                if (tmp >= 0 && tmp < h) {
                    tate[c].erase(it);
                    yoko[tmp].erase(c);
                }
            }

            it = tate[c].upper_bound(r);
            if (it != tate[c].end()) {
                int tmp = *it;
                if (tmp >= 0 && tmp < h) {
                    tate[c].erase(it);
                    yoko[tmp].erase(c);
                }
            }

            it = yoko[r].lower_bound(c);
            if (it != yoko[r].begin()) {
                --it;
                int tmp = *it;
                if (tmp >= 0 && tmp < w) {
                    yoko[r].erase(it);
                    tate[tmp].erase(r);
                }
            }

            it = yoko[r].upper_bound(c);
            if (it != yoko[r].end()) {
                int tmp = *it;
                if (tmp >= 0 && tmp < w) {
                    yoko[r].erase(it);
                    tate[tmp].erase(r);
                }
            }
        }
    }
    int ans = 0;
    rep(i, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}