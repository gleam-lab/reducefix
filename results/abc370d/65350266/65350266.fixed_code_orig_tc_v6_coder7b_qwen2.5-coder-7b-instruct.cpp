#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    set<pair<int, int>> s;

    rep(i, h) rep(j, w) {
        s.insert({i, j});
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;
        s.erase(s.find({r, c}));

        auto it = s.lower_bound({r, c});

        if (it != s.end() && it->first == r) {
            s.erase(it);
        }

        it = s.lower_bound({r, c});

        if (it != s.begin()) {
            --it;
            if (it->first == r) {
                s.erase(it);
            }
        }

        it = s.lower_bound({r, c});

        if (it != s.end() && it->second == c) {
            s.erase(it);
        }

        it = s.lower_bound({r, c});

        if (it != s.begin()) {
            --it;
            if (it->second == c) {
                s.erase(it);
            }
        }
    }

    cout << s.size() << endl;

    return 0;
}