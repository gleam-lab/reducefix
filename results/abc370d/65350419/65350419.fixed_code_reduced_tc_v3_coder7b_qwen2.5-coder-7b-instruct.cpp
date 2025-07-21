#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            auto tate_iter_l = tate[c].upper_bound(r);
            if (tate_iter_l != tate[c].begin()) {
                --tate_iter_l;
                int tmp = *tate_iter_l;
                if (tmp >= 0 && tmp < h) {
                    tate[c].erase(tmp);
                    yoko[tmp].erase(c);
                }
            }

            auto tate_iter_r = tate[c].lower_bound(r);
            if (tate_iter_r != tate[c].end()) {
                int tmp = *tate_iter_r;
                if (tmp >= 0 && tmp < h) {
                    tate[c].erase(tmp);
                    yoko[tmp].erase(c);
                }
            }
    
            auto yoko_iter_u = yoko[r].upper_bound(c);
            if (yoko_iter_u != yoko[r].begin()) {
                --yoko_iter_u;
                int tmp = *yoko_iter_u;
                if (tmp >= 0 && tmp < w) {
                    yoko[r].erase(tmp);
                    tate[tmp].erase(r);
                }
            }
    
            auto yoko_iter_d = yoko[r].lower_bound(c);
            if (yoko_iter_d != yoko[r].end()) {
                int tmp = *yoko_iter_d;
                if (tmp >= 0 && tmp < w) {
                    yoko[r].erase(tmp);
                    tate[tmp].erase(r);
                }
            }
    
        }
    }
    int ans = 0;
    rep(i,w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}