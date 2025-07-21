#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H + 1), col(W + 1);
    
    // Initialize all cells as walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row[R].count(C)) {
            // Wall exists at (R, C), destroy it
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // No wall at (R, C), destroy nearest walls in four directions
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                row[*it_up].erase(C);
                col[C].erase(it_up);
            }
            // Down
            auto it_down = col[C].lower_bound(R);
            if (it_down != col[C].end()) {
                row[*it_down].erase(C);
                col[C].erase(it_down);
            }
            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                col[*it_left].erase(R);
                row[R].erase(it_left);
            }
            // Right
            auto it_right = row[R].lower_bound(C);
            if (it_right != row[R].end()) {
                col[*it_right].erase(R);
                row[R].erase(it_right);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
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