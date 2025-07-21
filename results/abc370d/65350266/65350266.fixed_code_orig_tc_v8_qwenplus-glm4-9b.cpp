#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    vector<int> min_tate(w, 0), max_tate(w, h - 1);
    vector<int> min_yoko(h, 0), max_yoko(h, w - 1);

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Update min_tate and max_tate for the vertical direction
            min_tate[c] = *tate[c].lower_bound(r);
            max_tate[c] = *prev(tate[c].upper_bound(r));

            // Update min_yoko and max_yoko for the horizontal direction
            min_yoko[r] = *yoko[r].lower_bound(c);
            max_yoko[r] = *prev(yoko[r].upper_bound(c));

            // Find and remove walls from the set
            auto range = tate[c].equal_range(min_tate[c]);
            for (auto it = range.first; it != range.second; ++it) {
                if (*it <= max_tate[c]) {
                    yoko[*it].erase(c);
                    tate[c].erase(*it);
                } else {
                    break;
                }
            }

            range = yoko[r].equal_range(min_yoko[r]);
            for (auto it = range.first; it != range.second; ++it) {
                if (*it <= max_yoko[r]) {
                    tate[*it].erase(r);
                    yoko[r].erase(*it);
                } else {
                    break;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < w; i++) {
        ans += min_tate[i] - max_tate[i] + 1;
        ans += min_yoko[i] - max_yoko[i] + 1;
    }

    cout << ans << '\n';
    return 0;
}