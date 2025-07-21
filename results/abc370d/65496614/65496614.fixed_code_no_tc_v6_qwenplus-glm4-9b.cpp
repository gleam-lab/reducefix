#include <iostream>
#include <set>
#include <vector>

#define MAXN 400001 // Considering H * W can be at most 4 * 10^5

using namespace std;

vector<set<int>> row[MAXN];
vector<set<int>> col[MAXN];

void removeWall(int i, int j) {
    if (i == 0 || i == MAXN || j == 0 || j == MAXN) return;

    // Remove walls from the row
    auto it = row[i].lower_bound(j);
    if (it != row[i].begin()) {
        --it;
        row[i].erase(it);
    }
    if (it != row[i].end()) {
        row[i].erase(it);
    }

    // Remove walls from the column
    it = col[j].lower_bound(i);
    if (it != col[j].begin()) {
        --it;
        col[j].erase(it);
    }
    if (it != col[j].end()) {
        col[j].erase(it);
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 1; i <= MAXN; ++i) {
        row[i].reserve(w);
        col[i].reserve(h);
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        removeWall(r, c);
    }

    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remainingWalls += row[i].size() * col[j].size();
        }
    }

    cout << remainingWalls << endl;
    return 0;
}