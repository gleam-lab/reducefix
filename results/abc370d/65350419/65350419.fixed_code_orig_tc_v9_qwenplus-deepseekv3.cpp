#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
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
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                int target_r = *prev(it_up);
                tate[c].erase(target_r);
                yoko[target_r].erase(c);
            }
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int target_r = *it_down;
                tate[c].erase(target_r);
                yoko[target_r].erase(c);
            }
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                int target_c = *prev(it_left);
                yoko[r].erase(target_c);
                tate[target_c].erase(r);
            }
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int target_c = *it_right;
                yoko[r].erase(target_c);
                tate[target_c].erase(r);
            }
        }
    }
    int ans = 0;
    rep(i, h) ans += yoko[i].size();
    cout << ans << "\n";
    return 0;
}