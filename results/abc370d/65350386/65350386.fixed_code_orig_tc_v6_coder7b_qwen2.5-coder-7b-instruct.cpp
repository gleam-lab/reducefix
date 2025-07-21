#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (!tate[c].empty() && *(tate[c].begin()) == r) {
            tate[c].erase(tate[c].begin());
            yoko[r].erase(yoko[r].begin());
        } else {
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].begin()) {
                tate[c].erase(prev(it));
                yoko[*prev(it)].erase(c);
            }
            if (it != tate[c].end()) {
                tate[c].erase(it);
                yoko[*it].erase(c);
            }
            it = yoko[r].lower_bound(c);
            if (it != yoko[r].begin()) {
                yoko[r].erase(prev(it));
                tate[*prev(it)].erase(r);
            }
            if (it != yoko[r].end()) {
                yoko[r].erase(it);
                tate[*it].erase(r);
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