#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<set<int>>> walls(2, vector<set<int>>(W + 1));
    
    // Initialize the walls
    for (int h = 1; h <= H; ++h) {
        for (int w = 1; w <= W; ++w) {
            walls[0].at(w).insert(h); // update the row walls
            walls[1].at(h).insert(w); // update the column walls
        }
    }
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        // Check if there's a wall at the given cell
        if (!walls[0].at(c).count(r)) {
            continue; // No wall, skip this query
        }
        
        // Remove the wall at (r, c)
        walls[0].at(c).erase(r);
        walls[1].at(r).erase(c);
        
        // Remove walls in the four directions
        // North
        auto north = walls[1].at(r);
        auto it = north.lower_bound(c);
        if (it != north.begin()) {
            it--;
            walls[0].at(*it).erase(r);
        }
        
        // South
        auto south = walls[1].at(r);
        it = south.lower_bound(c);
        if (it != south.end()) {
            walls[0].at(*it).erase(r);
        }
        
        // East
        auto east = walls[0].at(c);
        it = east.lower_bound(r);
        if (it != east.begin()) {
            it--;
            walls[1].at(*it).erase(c);
        }
        
        // West
        auto west = walls[0].at(c);
        it = west.lower_bound(r);
        if (it != west.end()) {
            walls[1].at(*it).erase(c);
        }
    }
    
    // Count the remaining walls
    int remaining_walls = 0;
    for (int h = 1; h <= H; ++h) {
        for (int w = 1; w <= W; ++w) {
            remaining_walls += walls[0].at(w).size() + walls[1].at(h).size();
        }
    }
    
    cout << remaining_walls << endl;
    
    return 0;
}