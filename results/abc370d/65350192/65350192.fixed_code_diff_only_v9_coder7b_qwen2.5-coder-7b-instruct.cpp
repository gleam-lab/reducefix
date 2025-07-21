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
        r--, c--;

        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            auto tate_iter = tate[c].lower_bound(r);
            if (tate_iter != tate[c].end() && *tate_iter == r) {
                tate[c].erase(tate_iter);
                yoko[r].erase(c);
            }

            if (tate_iter != tate[c].begin()) {
                tate_iter--;
                if (*tate_iter == r - 1) {
                    tate[c].erase(tate_iter);
                    yoko[r].erase(c);
                }
            }

            auto yoko_iter = yoko[r].lower_bound(c);
            if (yoko_iter != yoko[r].end() && *yoko_iter == c) {
                yoko[r].erase(yoko_iter);
                tate[c].erase(c);
            }

            if (yoko_iter != yoko[r].begin()) {
                yoko_iter--;
                if (*yoko_iter == c - 1) {
                    yoko[r].erase(yoko_iter);
                    tate[c].erase(c);
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