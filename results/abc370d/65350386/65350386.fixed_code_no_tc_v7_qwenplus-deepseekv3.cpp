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
    ll ans = (ll)h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
            ans--;
        } else {
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].begin()) {
                int tmp = *prev(it);
                if (yoko[tmp].count(c)) {
                    tate[c].erase(tmp);
                    yoko[tmp].erase(c);
                    ans--;
                }
            }
            it = tate[c].upper_bound(r);
            if (it != tate[c].end()) {
                int tmp = *it;
                if (yoko[tmp].count(c)) {
                    tate[c].erase(tmp);
                    yoko[tmp].erase(c);
                    ans--;
                }
            }
            it = yoko[r].lower_bound(c);
            if (it != yoko[r].begin()) {
                int tmp = *prev(it);
                if (tate[tmp].count(r)) {
                    yoko[r].erase(tmp);
                    tate[tmp].erase(r);
                    ans--;
                }
            }
            it = yoko[r].upper_bound(c);
            if (it != yoko[r].end()) {
                int tmp = *it;
                if (tate[tmp].count(r)) {
                    yoko[r].erase(tmp);
                    tate[tmp].erase(r);
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}