#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i,n) for(int i = 1; i <= (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using pii = pair<int, int>;

// For each row and column, we'll maintain ordered sets of remaining wall positions
template<typename T>
class OrderedSet {
public:
    set<T> data;
    
    // Find the first element >= key
    typename set<T>::iterator lower_bound(const T& key) {
        return data.lower_bound(key);
    }
    
    // Insert an element
    void insert(const T& val) {
        data.insert(val);
    }
    
    // Erase an element
    void erase(const T& val) {
        data.erase(val);
    }
    
    // Check if empty
    bool empty() const {
        return data.empty();
    }
    
    // Get begin iterator
    typename set<T>::iterator begin() {
        return data.begin();
    }
    
    // Get end iterator
    typename set<T>::iterator end() {
        return data.end();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // Grid to track whether a wall exists at each cell
    vvb has_wall(H + 2, vb(W + 2, true));
    
    // For each row, keep track of walls in columns
    vector<OrderedSet<int>> row_sets(H + 2);
    // For each column, keep track of walls in rows
    vector<OrderedSet<int>> col_sets(W + 2);
    
    // Initialize all walls as present
    rep1(i, H) {
        rep1(j, W) {
            row_sets[i].insert(j);
            col_sets[j].insert(i);
        }
    }
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (has_wall[r][c]) {
            // If there's a wall at the position, destroy it and stop
            has_wall[r][c] = false;
            
            // Remove from row and column sets
            row_sets[r].erase(c);
            col_sets[c].erase(r);
        } else {
            // Otherwise, find the nearest walls in each direction
            
            // Left and right in the current row
            auto& row_set = row_sets[r];
            auto lit = row_set.lower_bound(c);
            if (lit != row_set.begin()) {
                --lit;
                int l = *lit;
                has_wall[r][l] = false;
                row_set.erase(lit);
                col_sets[l].erase(r);
            }
            
            auto rit = row_set.lower_bound(c);
            if (rit != row_set.end()) {
                int ri = *rit;
                has_wall[r][ri] = false;
                row_set.erase(rit);
                col_sets[ri].erase(r);
            }
            
            // Up and down in the current column
            auto& col_set = col_sets[c];
            auto uit = col_set.lower_bound(r);
            if (uit != col_set.begin()) {
                --uit;
                int u = *uit;
                has_wall[u][c] = false;
                col_set.erase(uit);
                row_sets[u].erase(c);
            }
            
            auto dit = col_set.lower_bound(r);
            if (dit != col_set.end()) {
                int d = *dit;
                has_wall[d][c] = false;
                col_set.erase(dit);
                row_sets[d].erase(c);
            }
        }
    }
    
    // Count remaining walls
    int ans = 0;
    rep1(i, H) {
        rep1(j, W) {
            ans += has_wall[i][j];
        }
    }
    
    cout << ans << endl;
    return 0;
}