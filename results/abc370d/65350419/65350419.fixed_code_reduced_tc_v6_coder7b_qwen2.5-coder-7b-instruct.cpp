#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<deque<int>> rows(h), cols(w);

    rep(i, h) rep(j, w) {
        rows[i].push_back(j);
        cols[j].push_back(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        bool hasWall = false;
        for (auto& d : rows[r]) {
            if (d == c) {
                hasWall = true;
                break;
            }
        }
        for (auto& d : cols[c]) {
            if (d == r) {
                hasWall = true;
                break;
            }
        }

        if (!hasWall) {
            while (!rows[r].empty() && rows[r].front() < c) rows[r].pop_front();
            while (!rows[r].empty() && rows[r].back() > c) rows[r].pop_back();

            while (!cols[c].empty() && cols[c].front() < r) cols[c].pop_front();
            while (!cols[c].empty() && cols[c].back() > r) cols[c].pop_back();
        } else {
            auto r_it = rows[r].begin(), r_end = rows[r].end();
            while (r_it != r_end && *r_it <= c) ++r_it;
            if (r_it != r_begin) --r_it;
            if (r_it != r_end) {
                cols[*r_it].erase(find(cols[*r_it].begin(), cols[*r_it].end(), r));
            }

            auto c_it = cols[c].begin(), c_end = cols[c].end();
            while (c_it != c_end && *c_it <= r) ++c_it;
            if (c_it != c_begin) --c_it;
            if (c_it != c_end) {
                rows[*c_it].erase(find(rows[*c_it].begin(), rows[*c_it].end(), c));
            }

            rows[r].erase(find(rows[r].begin(), rows[r].end(), c));
            cols[c].erase(find(cols[c].begin(), cols[c].end(), r));
        }
    }

    int ans = 0;
    rep(i, h) ans += rows[i].size();
    rep(i, w) ans += cols[i].size();
    cout << ans << "\n";

    return 0;
}