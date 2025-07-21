#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h);
    vector<set<int>> col_walls(w);
    
    for (int i = 0; i < h; ++i) {
        row_walls[i].insert(-1);
        row_walls[i].insert(w);
    }
    for (int j = 0; j < w; ++j) {
        col_walls[j].insert(-1);
        col_walls[j].insert(h);
    }
    
    long long remaining = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (!row_walls[r].count(c)) {
            // Wall exists, destroy it
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining--;
        } else {
            // Wall doesn't exist, destroy nearest walls in four directions
            // Left
            auto it = row_walls[r].lower_bound(c);
            it--;
            int left = *it;
            if (left != -1 && !row_walls[r].count(left)) {
                row_walls[r].insert(left);
                col_walls[left].insert(r);
                remaining--;
            }
            // Right
            it = row_walls[r].upper_bound(c);
            int right = *it;
            if (right != w && !row_walls[r].count(right)) {
                row_walls[r].insert(right);
                col_walls[right].insert(r);
                remaining--;
            }
            // Up
            it = col_walls[c].lower_bound(r);
            it--;
            int up = *it;
            if (up != -1 && !col_walls[c].count(up)) {
                col_walls[c].insert(up);
                row_walls[up].insert(c);
                remaining--;
            }
            // Down
            it = col_walls[c].upper_bound(r);
            int down = *it;
            if (down != h && !col_walls[c].count(down)) {
                col_walls[c].insert(down);
                row_walls[down].insert(c);
                remaining--;
            }
        }
    }
    
    cout << remaining << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}