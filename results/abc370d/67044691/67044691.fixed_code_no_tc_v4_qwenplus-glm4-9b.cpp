#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;

    vector<vector<set<ll>>> row(h, vector<set<ll>>(w));
    vector<vector<set<ll>>> col(w, vector<set<ll>>(h));

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row[i][j] = {i, j};
            col[j][i] = {i, j};
        }
    }

    for (ll i = 0; i < q; ++i) {
        ll r, c;
        cin >> r >> c;
        --r;
        --c;

        auto& rSet = row[r];
        auto& cSet = col[c];

        // Check if there's a wall at (r, c)
        if (rSet.find(c) != rSet.end() && cSet.find(r) != cSet.end()) {
            rSet.erase(c);
            cSet.erase(r);
        } else {
            // Try to remove walls in all four directions
            removeWalls(rSet, c, h, col);
            removeWalls(cSet, r, w, row);
        }
    }

    ll remainingWalls = 0;
    for (ll i = 0; i < h; ++i) {
        remainingWalls += row[i].size();
    }
    for (ll j = 0; j < w; ++j) {
        remainingWalls += col[j].size();
    }

    cout << remainingWalls << endl;
}

void removeWalls(vector<set<ll>>& walls, ll coordinate, ll size, vector<vector<set<ll>>>& grid) {
    ll left = lower_bound(walls.begin(), walls.end(), coordinate) - walls.begin();
    ll right = upper_bound(walls.begin(), walls.end(), coordinate) - walls.begin() - 1;

    if (left < size && (left == 0 || walls[left - 1] != coordinate)) {
        walls.erase(left);
    }
    if (right >= 0 && (right == size - 1 || walls[right + 1] != coordinate)) {
        walls.erase(right);
    }
}