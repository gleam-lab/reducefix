#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define all(v) begin(v), end(v)
#define debug(...) //cerr << #__VA_ARGS__ << " = " << make_tuple(__VA_ARGS__) << endl

const int INF = 1e9 + 5;

struct Cell {
    bool wall = true;
};

struct BombProcessor {
    int H, W, Q;
    vector<map<int, int>> row_map; // row_map[r] stores columns in row r that have bombs
    vector<map<int, int>> col_map; // col_map[c] stores rows in column c that have bombs
    
    BombProcessor(int h, int w) : H(h), W(w) {
        row_map.resize(H);
        col_map.resize(W);
    }
    
    void processQuery(int r, int c) {
        --r; --c; // converting to 0-based index
        
        if (!hasBombAt(r, c)) {
            addBomb(r, c);
            return;
        }
        
        // Look up
        auto it_up = col_map[c].lower_bound(r);
        if (it_up != col_map[c].begin()) {
            --it_up;
            int destroy_r = it_up->first;
            removeBomb(destroy_r, c);
        }
        
        // Look down
        auto it_down = col_map[c].upper_bound(r);
        if (it_down != col_map[c].end()) {
            int destroy_r = it_down->first;
            removeBomb(destroy_r, c);
        }
        
        // Look left
        auto it_left = row_map[r].lower_bound(c);
        if (it_left != row_map[r].begin()) {
            --it_left;
            int destroy_c = it_left->first;
            removeBomb(r, destroy_c);
        }
        
        // Look right
        auto it_right = row_map[r].upper_bound(c);
        if (it_right != row_map[r].end()) {
            int destroy_c = it_right->first;
            removeBomb(r, destroy_c);
        }
    }
    
    bool hasBombAt(int r, int c) {
        return row_map[r].count(c) > 0;
    }
    
    void addBomb(int r, int c) {
        row_map[r][c] = c;
        col_map[c][r] = r;
    }
    
    void removeBomb(int r, int c) {
        row_map[r].erase(c);
        col_map[c].erase(r);
    }
    
    int countRemainingWalls() {
        ll totalBombs = 0;
        for (int r = 0; r < H; ++r) {
            totalBombs += row_map[r].size();
        }
        return H * W - totalBombs;
    }
};

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    BombProcessor processor(H, W);
    
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        processor.processQuery(r, c);
    }
    
    cout << processor.countRemainingWalls() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}