#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

template<typename T>
struct GridMap {
    map<int, T> data;
    
    bool has(int x, int y) const {
        auto it = data.find(x);
        return it != data.end() && it->second.count(y);
    }
    
    void add(int x, int y) {
        data[x][y] = true;
    }
    
    void remove(int x, int y) {
        if (data.contains(x)) {
            data[x].erase(y);
            if (data[x].empty()) {
                data.erase(x);
            }
        }
    }
};

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // For each row and column, track which cells have bombs
    vector<map<int, bool>> row_bombs(H), col_bombs(W);
    
    // Track which cells have been bombed
    set<pair<int, int>> bombed;
    
    for (int i = 0; i < Q; ++i) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        
        if (bombed.count({R, C})) {
            // Bomb in adjacent cells
            
            // Up direction
            auto up_it = col_bombs[C].lower_bound(R);
            if (up_it != col_bombs[C].begin()) {
                up_it--;
                int r = up_it->first;
                bombed.erase({r, C});
                col_bombs[r].erase(C);
                row_bombs[r].erase(C);
            }
            
            // Down direction
            auto down_it = col_bombs[C].lower_bound(R);
            if (down_it != col_bombs[C].end()) {
                int r = down_it->first;
                bombed.erase({r, C});
                col_bombs[r].erase(C);
                row_bombs[r].erase(C);
            }
            
            // Left direction
            auto left_it = row_bombs[R].lower_bound(C);
            if (left_it != row_bombs[R].begin()) {
                left_it--;
                int c = left_it->first;
                bombed.erase({R, c});
                row_bombs[R].erase(c);
                col_bombs[c].erase(R);
            }
            
            // Right direction
            auto right_it = row_bombs[R].lower_bound(C);
            if (right_it != row_bombs[R].end()) {
                int c = right_it->first;
                bombed.erase({R, c});
                row_bombs[R].erase(c);
                col_bombs[c].erase(R);
            }
        } else {
            // Place bomb
            bombed.insert({R, C});
            row_bombs[R][C] = true;
            col_bombs[C][R] = true;
        }
    }
    
    cout << (H * W - bombed.size()) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}