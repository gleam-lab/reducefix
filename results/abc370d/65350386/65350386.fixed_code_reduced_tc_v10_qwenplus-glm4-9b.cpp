#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<pair<int, int>>> tate(w), yoko(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tate[j].insert({i, j});
            yoko[i].insert({i, j});
        }
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[c].find({r, c}) != tate[c].end()) {
            tate[c].erase({r, c});
            yoko[r].erase({r, c});
        } else {
            // Destroy vertical walls
            int bound = min(r - 1, h - 1);
            for (int i = 0; i <= bound; i++) {
                auto it = tate[c].lower_bound({i, c});
                if (it != tate[c].end() && (*it).first == i && (*it).second == c) {
                    tate[c].erase(it);
                    yoko[i].erase({i, c});
                    break;
                }
            }
            bound = max(0, r);
            for (int i = bound; i < h; i++) {
                auto it = tate[c].lower_bound({i, c});
                if (it != tate[c].end() && (*it).first == i && (*it).second == c) {
                    tate[c].erase(it);
                    yoko[i].erase({i, c});
                    break;
                }
            }

            // Destroy horizontal walls
            bound = min(c - 1, w - 1);
            for (int j = 0; j <= bound; j++) {
                auto it = yoko[r].lower_bound({r, j});
                if (it != yoko[r].end() && (*it).first == r && (*it).second == j) {
                    tate[j].erase(it);
                    yoko[r].erase(it);
                    break;
                }
            }
            bound = max(0, c);
            for (int j = bound; j < w; j++) {
                auto it = yoko[r].lower_bound({r, j});
                if (it != yoko[r].end() && (*it).first == r && (*it).second == j) {
                    tate[j].erase(it);
                    yoko[r].erase(it);
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; i++) {
        ans += tate[i].size();
    }

    cout << ans << endl;
    return 0;
}