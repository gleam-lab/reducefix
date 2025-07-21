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
    int ans = h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
            ans--;
        } else {
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                it_up--;
                int tmp = *it_up;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
                ans--;
            }
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int tmp = *it_down;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
                ans--;
            }
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                it_left--;
                int tmp = *it_left;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
                ans--;
            }
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int tmp = *it_right;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
                ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}