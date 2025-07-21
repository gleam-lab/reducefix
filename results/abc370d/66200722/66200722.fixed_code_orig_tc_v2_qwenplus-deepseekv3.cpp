#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rows(H + 1);
    vector<set<int>> cols(W + 1);
    
    long long walls = (long long)H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
            walls++;
        } else {
            // Check up
            auto it_up = cols[C].lower_bound(R);
            if (it_up != cols[C].begin()) {
                --it_up;
                int r = *it_up;
                rows[r].erase(C);
                cols[C].erase(r);
                walls++;
            }
            
            // Check down
            auto it_down = cols[C].upper_bound(R);
            if (it_down != cols[C].end()) {
                int r = *it_down;
                rows[r].erase(C);
                cols[C].erase(r);
                walls++;
            }
            
            // Check left
            auto it_left = rows[R].lower_bound(C);
            if (it_left != rows[R].begin()) {
                --it_left;
                int c = *it_left;
                rows[R].erase(c);
                cols[c].erase(R);
                walls++;
            }
            
            // Check right
            auto it_right = rows[R].upper_bound(C);
            if (it_right != rows[R].end()) {
                int c = *it_right;
                rows[R].erase(c);
                cols[c].erase(R);
                walls++;
            }
            
            rows[R].insert(C);
            cols[C].insert(R);
            walls--;
        }
    }
    
    cout << walls << '\n';
    
    return 0;
}