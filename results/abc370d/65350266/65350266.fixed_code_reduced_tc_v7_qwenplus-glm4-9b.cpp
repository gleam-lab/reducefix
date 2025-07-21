#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(h), yoko(w);
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            tate[i].insert(j);
            yoko[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        auto tate_end = tate[r].end();
        auto yoko_end = yoko[c].end();

        // Check and remove the wall at (r, c) if it exists
        if (tate[r].find(c) != tate_end) {
            tate[r].erase(c);
            yoko[c].erase(r);
        } else {
            // Remove walls above (r, c) if they exist
            auto tate_iter = tate[r].lower_bound(c);
            if (tate_iter != tate_end) {
                tate[r].erase(tate_iter);
                yoko[*tate_iter].erase(r);
            }
            // Remove walls below (r, c) if they exist
            auto tate_rev_iter = tate.rbegin();
            while (tate_rev_iter->first < r) {
                ++tate_rev_iter;
            }
            if (tate_rev_iter != tate.rend()) {
                tate_iter = tate[r].lower_bound(c);
                if (tate_iter != tate_end) {
                    tate[r].erase(tate_iter);
                    yoko[*tate_iter].erase(r);
                }
            }
            // Remove walls to the left of (r, c) if they exist
            auto yoko_iter = yoko[c].lower_bound(r);
            if (yoko_iter != yoko_end) {
                yoko[c].erase(yoko_iter);
                tate[*yoko_iter].erase(c);
            }
            // Remove walls to the right of (r, c) if they exist
            auto yoko_rev_iter = yoko.rbegin();
            while (yoko_rev_iter->first < c) {
                ++yoko_rev_iter;
            }
            if (yoko_rev_iter != yoko.rend()) {
                yoko_iter = yoko[c].lower_bound(r);
                if (yoko_iter != yoko_end) {
                    yoko[c].erase(yoko_iter);
                    tate[*yoko_iter].erase(c);
                }
            }
        }
    }

    int remaining_walls = 0;
    for (const auto &set : tate) {
        remaining_walls += set.size();
    }
    for (const auto &set : yoko) {
        remaining_walls += set.size();
    }
    cout << remaining_walls << endl;
    return 0;
}