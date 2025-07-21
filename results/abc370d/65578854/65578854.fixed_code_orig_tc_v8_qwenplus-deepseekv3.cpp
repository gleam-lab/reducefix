#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    ll remaining = (ll)H * W;
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining--;
        } else {
            // Check up direction
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int r = *it_up;
                if (row_walls[r].count(C)) {
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                    remaining--;
                }
            }
            
            // Check down direction
            auto it_down = col_walls[C].lower_bound(R);
            if (it_down != col_walls[C].end()) {
                int r = *it_down;
                if (row_walls[r].count(C)) {
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                    remaining--;
                }
            }
            
            // Check left direction
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int c = *it_left;
                if (col_walls[c].count(R)) {
                    col_walls[c].erase(R);
                    row_walls[R].erase(c);
                    remaining--;
                }
            }
            
            // Check right direction
            auto it_right = row_walls[R].lower_bound(C);
            if (it_right != row_walls[R].end()) {
                int c = *it_right;
                if (col_walls[c].count(R)) {
                    col_walls[c].erase(R);
                    row_walls[R].erase(c);
                    remaining--;
                }
            }
        }
    }
    
    cout << remaining << endl;
    
    return 0;
}