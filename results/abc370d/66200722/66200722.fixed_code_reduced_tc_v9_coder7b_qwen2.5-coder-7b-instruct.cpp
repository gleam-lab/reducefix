#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<unordered_set<int>> grid(h);
    vector<bool> destroyed(h * w, false);
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (!grid[r].insert(c).second) {
            continue;
        }
        
        int index = r * w + c;
        destroyed[index] = true;
        
        // Check up
        for (int i = r - 1; i >= 0 && !destroyed[i * w + c]; --i) {
            destroyed[i * w + c] = true;
        }
        
        // Check down
        for (int i = r + 1; i < h && !destroyed[i * w + c]; ++i) {
            destroyed[i * w + c] = true;
        }
        
        // Check left
        for (int j = c - 1; j >= 0 && !destroyed[r * w + j]; --j) {
            destroyed[r * w + j] = true;
        }
        
        // Check right
        for (int j = c + 1; j < w && !destroyed[r * w + j]; ++j) {
            destroyed[r * w + j] = true;
        }
    }
    
    int remaining_walls = 0;
    for (bool d : destroyed) {
        if (!d) {
            ++remaining_walls;
        }
    }
    
    cout << remaining_walls << endl;
    
    return 0;
}