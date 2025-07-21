#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    set<pair<int, int>> s;
    rep(i, h) rep(j, w) {
        s.insert({i, j});
    }
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (grid[r][c]) {
            grid[r][c] = false;
            s.erase(s.find({r, c}));
        } else {
            auto it = s.lower_bound({r, c});
            while (it != s.end() && it->first == r) {
                if (!grid[it->second][c]) {
                    s.erase(it++);
                } else {
                    break;
                }
            }
            it = s.lower_bound({r, c});
            while (it != s.begin()) {
                --it;
                if (!grid[it->first][c]) {
                    s.erase(it);
                } else {
                    break;
                }
            }
            it = s.lower_bound({r, c});
            while (it != s.end() && it->second == c) {
                if (!grid[it->first][c]) {
                    s.erase(it++);
                } else {
                    break;
                }
            }
            it = s.lower_bound({r, c});
            while (it != s.begin()) {
                --it;
                if (!grid[it->first][c]) {
                    s.erase(it);
                } else {
                    break;
                }
            }
        }
    }
    cout << s.size() << "\n";
    return 0;
}