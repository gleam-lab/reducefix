#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> vertical(h + 2), horizontal(w + 2);

    // Initialize the vertical and horizontal walls
    for (int i = 1; i <= h; ++i) {
        vertical[i].insert(0);
        vertical[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        horizontal[j].insert(0);
        horizontal[j].insert(h + 1);
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (vertical[c].lower_bound(r) != vertical[c].end() && *vertical[c].lower_bound(r) == r) {
            vertical[c].erase(r);
            horizontal[r].erase(c);
        } else {
            // Find and remove the topmost wall
            auto it = vertical[c].lower_bound(r);
            if (it != vertical[c].begin()) {
                --it;
                vertical[c].erase(*it);
                horizontal[*it].erase(c);
            }

            // Find and remove the bottommost wall
            it = vertical[c].upper_bound(r);
            if (it != vertical[c].end()) {
                vertical[c].erase(*it);
                horizontal[*it].erase(c);
            }

            // Find and remove the leftmost wall
            it = horizontal[r].lower_bound(c);
            if (it != horizontal[r].begin()) {
                --it;
                horizontal[r].erase(*it);
                vertical[*it].erase(r);
            }

            // Find and remove the rightmost wall
            it = horizontal[r].upper_bound(c);
            if (it != horizontal[r].end()) {
                horizontal[r].erase(*it);
                vertical[*it].erase(r);
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        remainingWalls += vertical[i].size() - 2;
    }
    for (int j = 1; j <= w; ++j) {
        remainingWalls += horizontal[j].size() - 2;
    }

    cout << remainingWalls << endl;
    return 0;
}