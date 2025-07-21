#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) {
        rep(j, w) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        // Check if there's a wall at the exact location and remove it if present
        if (tate[c].find(r) != tate[c].end()) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // If no wall at (r, c), remove walls up, down, left, right
            // Check and remove walls up
            auto iter = tate[c].lower_bound(r);
            if (iter != tate[c].end()) {
                tate[c].erase(iter);
                yoko[*iter].erase(c);
            }
            iter = tate[c].lower_bound(r);
            if (iter != tate[c].begin()) {
                iter--;
                tate[c].erase(iter);
                yoko[*iter].erase(c);
            }
            // Check and remove walls down
            iter = tate[c].lower_bound(r);
            if (iter != tate[c].end()) {
                tate[c].erase(iter);
                yoko[*iter].erase(c);
            }
            // Check and remove walls left
            iter = yoko[r].lower_bound(c);
            if (iter != yoko[r].end()) {
                yoko[r].erase(iter);
                tate[*iter].erase(r);
            }
            iter = yoko[r].lower_bound(c);
            if (iter != yoko[r].begin()) {
                iter--;
                yoko[r].erase(iter);
                tate[*iter].erase(r);
            }
            // Check and remove walls right
            iter = yoko[r].lower_bound(c);
            if (iter != yoko[r].end()) {
                yoko[r].erase(iter);
                tate[*iter].erase(r);
            }
            iter = yoko[r].lower_bound(c);
            if (iter != yoko[r].begin()) {
                iter--;
                yoko[r].erase(iter);
                tate[*iter].erase(r);
            }
        }
    }
    // Calculate the remaining number of walls
    int remaining_walls = 0;
    for (const auto& row : tate) {
        remaining_walls += row.size();
    }
    cout << remaining_walls << endl;
    return 0;
}