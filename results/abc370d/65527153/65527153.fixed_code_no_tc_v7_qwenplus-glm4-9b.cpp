#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> st1(h + 1), st2(w + 1);

    // Initialize the walls in each cell
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            st1[i].insert(j);
            st2[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        // Check if there's a wall at the given cell
        if (st1[r].find(c) == st1[r].end()) {
            // No wall at (r, c), destroy walls around
            // Remove walls from the row
            auto it = st1[r].lower_bound(c);
            while (it != st1[r].end()) {
                st1[r].erase(it++);
                st2[*it].erase(r);
            }
            // Remove walls from the column
            it = st2[c].lower_bound(r);
            while (it != st2[c].end()) {
                st2[c].erase(it++);
                st1[*it].erase(c);
            }
        } else {
            // There is a wall at (r, c), destroy it
            st1[r].erase(c);
            st2[c].erase(r);
        }
    }

    // Calculate the number of remaining walls
    long long remaining_walls = 0;
    for (int i = 1; i <= h; i++) {
        remaining_walls += st1[i].size();
    }
    for (int j = 1; j <= w; j++) {
        remaining_walls += st2[j].size();
    }

    cout << remaining_walls << endl;

    return 0;
}