#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);

    // Initialize sets with indices representing wall positions
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            yoko[i].insert(j);
            tate[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to zero-based index

        if (yoko[r].find(c) != yoko[r].end()) {
            yoko[r].erase(c);
            tate[c].erase(r);
        } else {
            // Remove walls in the same row above (if any)
            auto iter_up = yoko[r].upper_bound(c);
            if (iter_up != yoko[r].begin()) {
                iter_up--;
                int up_col = *iter_up;
                if (up_col < w && tate[up_col].find(r) == tate[up_col].end()) {
                    yoko[r].erase(up_col);
                    tate[up_col].erase(r);
                }
            }

            // Remove walls in the same row below (if any)
            auto iter_down = yoko[r].lower_bound(c);
            if (iter_down != yoko[r].end()) {
                int down_col = *iter_down;
                if (down_col < w && tate[down_col].find(r) == tate[down_col].end()) {
                    yoko[r].erase(down_col);
                    tate[down_col].erase(r);
                }
            }

            // Remove walls in the same column to the left (if any)
            auto iter_left = tate[c].upper_bound(r);
            if (iter_left != tate[c].begin()) {
                iter_left--;
                int left_row = *iter_left;
                if (left_row < h && yoko[left_row].find(c) == yoko[left_row].end()) {
                    tate[c].erase(left_row);
                    yoko[left_row].erase(c);
                }
            }

            // Remove walls in the same column to the right (if any)
            auto iter_right = tate[c].lower_bound(r);
            if (iter_right != tate[c].end()) {
                int right_row = *iter_right;
                if (right_row < h && yoko[right_row].find(c) == yoko[right_row].end()) {
                    tate[c].erase(right_row);
                    yoko[right_row].erase(c);
                }
            }
        }
    }

    // Calculate the total number of remaining walls
    int ans = 0;
    for (const auto& set : tate) {
        ans += set.size();
    }
    cout << ans << "\n";

    return 0;
}