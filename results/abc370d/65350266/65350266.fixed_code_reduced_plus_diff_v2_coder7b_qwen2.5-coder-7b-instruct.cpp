#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    int total_walls = h * w;

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
            total_walls--;
        } else {
            auto tate_iter_r = tate[c].lower_bound(r);
            if (tate_iter_r != tate[c].end()) {
                int tmp = *tate_iter_r;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
                total_walls--;
            }

            auto tate_iter_l = tate[c].lower_bound(r);
            if (*tate_iter_l != *tate[c].begin()) {
                tate_iter_l--;
            }

            int tmp = *tate_iter_l;
            tate[c].erase(tmp);
            yoko[tmp].erase(c);
            total_walls--;

            auto yoko_iter_d = yoko[r].lower_bound(c);
            if (yoko_iter_d != yoko[r].end()) {
                int tmp = *yoko_iter_d;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
                total_walls--;
            }

            auto yoko_iter_u = yoko[r].lower_bound(c);
            if (*yoko_iter_u != *yoko[r].begin()) {
                yoko_iter_u--;
            }

            tmp = *yoko_iter_u;
            yoko[r].erase(tmp);
            tate[tmp].erase(r);
            total_walls--;
        }
    }

    cout << total_walls << "\n";
    return 0;
}