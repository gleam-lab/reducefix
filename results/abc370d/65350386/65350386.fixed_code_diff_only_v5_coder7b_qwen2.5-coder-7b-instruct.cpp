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
        if (!tate[c].empty() && *tate[c].rbegin() == r) {
            tate[c].erase(tate[c].find(r));
            yoko[r].erase(yoko[r].find(c));
        } else {
            auto tate_iter_l = tate[c].lower_bound(r);
            if (tate_iter_l != tate[c].begin()) {
                tate_iter_l--;
                int tmp = *tate_iter_l;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }
            if (tate_iter_l != tate[c].end()) {
                tate[c].erase(*tate_iter_l);
                yoko[*tate_iter_l].erase(c);
            }
            auto yoko_iter_u = yoko[r].lower_bound(c);
            if (yoko_iter_u != yoko[r].begin()) {
                yoko_iter_u--;
                int tmp = *yoko_iter_u;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
            if (yoko_iter_u != yoko[r].end()) {
                yoko[r].erase(*yoko_iter_u);
                tate[*yoko_iter_u].erase(r);
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