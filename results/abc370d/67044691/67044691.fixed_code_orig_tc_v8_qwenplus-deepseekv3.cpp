#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rows(H);
    vector<set<int>> cols(W);
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
        } else {
            vector<pair<int, int>> to_remove;
            
            // Left
            auto it_left = rows[R].lower_bound(C);
            if (it_left != rows[R].begin()) {
                --it_left;
                to_remove.emplace_back(R, *it_left);
            }
            
            // Right
            auto it_right = rows[R].upper_bound(C);
            if (it_right != rows[R].end()) {
                to_remove.emplace_back(R, *it_right);
            }
            
            // Up
            auto it_up = cols[C].lower_bound(R);
            if (it_up != cols[C].begin()) {
                --it_up;
                to_remove.emplace_back(*it_up, C);
            }
            
            // Down
            auto it_down = cols[C].upper_bound(R);
            if (it_down != cols[C].end()) {
                to_remove.emplace_back(*it_down, C);
            }
            
            for (auto &p : to_remove) {
                rows[p.first].erase(p.second);
                cols[p.second].erase(p.first);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += rows[i].size();
    }
    cout << ans << '\n';

    return 0;
}