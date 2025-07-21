#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h + 2);
    vector<set<int>> col(w + 2);
    
    // Initialize row and col sets with all possible positions
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int remaining = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].count(c)) {
            // Case 1: There's a wall at (r, c)
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        } else {
            // Case 2: No wall at (r, c), find first walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                row[*it_up].erase(c);
                col[c].erase(it_up);
                remaining--;
            }
            
            // Down
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                row[*it_down].erase(c);
                col[c].erase(it_down);
                remaining--;
            }
            
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                row[r].erase(*it_left);
                col[*it_left].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                row[r].erase(*it_right);
                col[*it_right].erase(r);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';
    return 0;
}