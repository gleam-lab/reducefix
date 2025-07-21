#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 200020;
vector<set<int>> rows, cols;

void erase_wall(int r, int c) {
    rows[r].erase(c);
    cols[c].erase(r);
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    rows.resize(h + 1);
    cols.resize(w + 1);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (rows[r].count(c)) {
            // Wall exists at the given cell
            erase_wall(r, c);
        } else {
            // Find the nearest wall to the left and right
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                erase_wall(r, *it);
            }
            if (it != rows[r].end()) {
                erase_wall(r, *it);
            }
            
            // Find the nearest wall above and below
            it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                erase_wall(*it, c);
            }
            if (it != cols[c].end()) {
                erase_wall(*it, c);
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 1; i <= h; i++) {
        remaining_walls += rows[i].size();
    }
    for (int j = 1; j <= w; j++) {
        remaining_walls += cols[j].size();
    }

    cout << remaining_walls << endl;
    return 0;
}