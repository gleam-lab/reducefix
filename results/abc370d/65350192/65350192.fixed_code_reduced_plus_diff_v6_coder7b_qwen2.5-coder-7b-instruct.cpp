#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!tate[c].empty() && *tate[c].begin() == r) {
            tate[c].erase(tate[c].begin());
            yoko[r].erase(yoko[r].begin());
        } else {
            auto it_c = tate[c].lower_bound(r);
            if (it_c != tate[c].end() && *it_c == r) {
                tate[c].erase(it_c);
                yoko[r].erase(r);
            }

            if (it_c != tate[c].begin()) {
                it_c--;
                int idx = *it_c;
                tate[c].erase(idx);
                yoko[idx].erase(c);
            }

            auto it_r = yoko[r].lower_bound(c);
            if (it_r != yoko[r].end() && *it_r == c) {
                yoko[r].erase(it_r);
                tate[c].erase(c);
            }

            if (it_r != yoko[r].begin()) {
                it_r--;
                int idx = *it_r;
                yoko[r].erase(idx);
                tate[idx].erase(r);
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