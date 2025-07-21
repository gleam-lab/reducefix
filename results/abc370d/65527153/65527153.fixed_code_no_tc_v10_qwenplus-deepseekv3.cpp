#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H + 1), col(W + 1);
    
    // Initialize the sets with all walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        // Check if there's a wall at (R, C)
        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            continue;
        }
        
        // Check for the nearest walls in each direction
        // Up
        auto it_up = col[C].lower_bound(R);
        if (it_up != col[C].begin()) {
            --it_up;
            int r = *it_up;
            row[r].erase(C);
            col[C].erase(r);
        }
        
        // Down
        auto it_down = col[C].lower_bound(R);
        if (it_down != col[C].end()) {
            int r = *it_down;
            row[r].erase(C);
            col[C].erase(r);
        }
        
        // Left
        auto it_left = row[R].lower_bound(C);
        if (it_left != row[R].begin()) {
            --it_left;
            int c = *it_left;
            row[R].erase(c);
            col[c].erase(R);
        }
        
        // Right
        auto it_right = row[R].lower_bound(C);
        if (it_right != row[R].end()) {
            int c = *it_right;
            row[R].erase(c);
            col[c].erase(R);
        }
    }
    
    // Count remaining walls
    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}