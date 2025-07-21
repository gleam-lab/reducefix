#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Read and process each query
    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        
        // Check if there is a wall at the given cell
        auto tate_iter = tate[c].find(r);
        if (tate_iter != tate[c].end()) {
            // Destroy the wall at (r, c)
            tate[c].erase(tate_iter);
            yoko[r].erase(c);
        } else {
            // Attempt to destroy walls in all four directions
            // Vertical walls to the left of (r, c)
            auto tate_left = tate[c].upper_bound(r);
            if (tate_left != tate[c].begin()) {
                --tate_left;
                tate[c].erase(tate_left);
                yoko[*tate_left].erase(c);
            }
            // Vertical walls to the right of (r, c)
            tate_left = tate[c].lower_bound(r);
            if (tate_left != tate[c].end()) {
                tate[c].erase(tate_left);
                yoko[*tate_left].erase(c);
            }
            // Horizontal walls above (r, c)
            auto yoko_up = yoko[r].upper_bound(c);
            if (yoko_up != yoko[r].begin()) {
                --yoko_up;
                yoko[r].erase(yoko_up);
                tate[*yoko_up].erase(r);
            }
            // Horizontal walls below (r, c)
            yoko_up = yoko[r].lower_bound(c);
            if (yoko_up != yoko[r].end()) {
                yoko[r].erase(yoko_up);
                tate[*yoko_up].erase(r);
            }
        }
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (const auto& t : tate) {
        remaining_walls += t.size();
    }
    for (const auto& y : yoko) {
        remaining_walls += y.size();
    }

    // Output the result
    cout << remaining_walls << endl;

    return 0;
}