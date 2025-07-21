#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) rep(j, w) {
        tate[j].insert(i + 1);
        yoko[i].insert(j + 1);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        if (tate[c - 1].count(r)) {
            tate[c - 1].erase(r);
            yoko[r - 1].erase(c);
        } else {
            // Up
            auto it_up = tate[c - 1].lower_bound(r);
            if (it_up != tate[c - 1].begin()) {
                --it_up;
                int tmp_r = *it_up;
                tate[c - 1].erase(tmp_r);
                yoko[tmp_r - 1].erase(c);
            }
            // Down
            auto it_down = tate[c - 1].lower_bound(r);
            if (it_down != tate[c - 1].end()) {
                int tmp_r = *it_down;
                tate[c - 1].erase(tmp_r);
                yoko[tmp_r - 1].erase(c);
            }
            // Left
            auto it_left = yoko[r - 1].lower_bound(c);
            if (it_left != yoko[r - 1].begin()) {
                --it_left;
                int tmp_c = *it_left;
                yoko[r - 1].erase(tmp_c);
                tate[tmp_c - 1].erase(r);
            }
            // Right
            auto it_right = yoko[r - 1].lower_bound(c);
            if (it_right != yoko[r - 1].end()) {
                int tmp_c = *it_right;
                yoko[r - 1].erase(tmp_c);
                tate[tmp_c - 1].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, w) ans += tate[i].size();
    cout << ans << "\n";

    return 0;
}