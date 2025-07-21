#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w + 1), yoko(h + 1);
    rep(i, h) rep(j, w) {
        tate[j + 1].insert(i + 1);
        yoko[i + 1].insert(j + 1);
    }
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].end()) {
                int tmp = *it;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }
            it = tate[c].lower_bound(r);
            if (it != tate[c].begin()) {
                it--;
                int tmp = *it;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }
            it = yoko[r].lower_bound(c);
            if (it != yoko[r].end()) {
                int tmp = *it;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
            it = yoko[r].lower_bound(c);
            if (it != yoko[r].begin()) {
                it--;
                int tmp = *it;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
        }
    }
    int ans = 0;
    rep(j, w + 1) ans += tate[j].size();
    cout << ans << endl;
    return 0;
}