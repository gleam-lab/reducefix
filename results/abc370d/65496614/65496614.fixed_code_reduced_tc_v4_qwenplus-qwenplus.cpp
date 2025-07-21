#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i,n) for(int i = 1; i <= (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

template<typename T>
using vec = vector<T>;

// Main data structures
vec<set<int>> row_sets;
vec<set<int>> col_sets;
vvb has_wall;

int H, W;

// Function to destroy the wall at (r, c)
void destroy(int r, int c) {
    if (r < 1 || r > H || c < 1 || c > W || !has_wall[r][c]) return;
    has_wall[r][c] = false;
    
    // Remove from row set
    row_sets[r].erase(c);
    // Remove from col set
    col_sets[c].erase(r);
}

void process_query(int r, int c) {
    if (has_wall[r][c]) {
        // Cell has a wall, just destroy it
        destroy(r, c);
        return;
    }
    
    // Otherwise, look in four directions and destroy first walls found

    // Up and Down (same column)
    auto& col_set = col_sets[c];
    auto it = col_set.lower_bound(r);
    
    // Up: find largest row less than r
    if (it != col_set.begin()) {
        --it;
        int up_r = *it;
        if (up_r >= 1 && up_r < r) {
            destroy(up_r, c);
        }
    }
    
    // Down: find smallest row greater than r
    ++it; // reset to r position
    ++it; // move past r
    if (it != col_set.end()) {
        int down_r = *it;
        if (down_r > r) {
            destroy(down_r, c);
        }
    }
    
    // Left and Right (same row)
    auto& row_set = row_sets[r];
    it = row_set.lower_bound(c);
    
    // Left: find largest column less than c
    if (it != row_set.begin()) {
        --it;
        int left_c = *it;
        if (left_c >= 1 && left_c < c) {
            destroy(r, left_c);
        }
    }
    
    // Right: find smallest column greater than c
    ++it; // reset to c position
    ++it; // move past c
    if (it != row_set.end()) {
        int right_c = *it;
        if (right_c > c) {
            destroy(r, right_c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> H >> W;
    int Q;
    cin >> Q;

    // Initialize
    has_wall.assign(H + 2, vb(W + 2, true)); // 1-based indexing
    row_sets.resize(H + 2);
    col_sets.resize(W + 2);

    // Initialize sets with all columns for each row, and all rows for each column
    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            row_sets[r].insert(c);
            col_sets[c].insert(r);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        process_query(r, c);
    }

    // Count remaining walls
    int ans = 0;
    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            ans += has_wall[r][c];
        }
    }

    cout << ans << endl;
    return 0;
}