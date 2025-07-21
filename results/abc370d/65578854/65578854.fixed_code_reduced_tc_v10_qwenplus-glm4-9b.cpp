#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<pair<int, int>>> horizontal(h);
    vector<set<pair<int, int>>> vertical(w);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            horizontal[i].insert({i, j});
            vertical[j].insert({i, j});
        }
    }

    ll remainingWalls = h * w;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        bool destroyed = false;

        // Check for wall to destroy
        if (!horizontal[r].empty() && horizontal[r].find({r, c}) != horizontal[r].end()) {
            horizontal[r].erase({r, c});
            vertical[c].erase({r, c});
            remainingWalls--;
            destroyed = true;
        }

        if (!destroyed) {
            // Destroy horizontal walls
            auto it = vertical[c].lower_bound({r, c});
            if (it != vertical[c].begin()) {
                it--;
                int prev_row = it->first;
                while (it != vertical[c].end() && it->first == prev_row) {
                    horizontal[prev_row].erase({prev_row, c});
                    vertical[c].erase(it++);
                }
            }
            it = vertical[c].upper_bound({r, c});
            if (it != vertical[c].end()) {
                while (it != vertical[c].end() && it->first == r) {
                    horizontal[prev_row].erase({prev_row, c});
                    vertical[c].erase(it++);
                }
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}