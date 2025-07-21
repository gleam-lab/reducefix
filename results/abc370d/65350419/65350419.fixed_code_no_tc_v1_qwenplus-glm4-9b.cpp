#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> tate(w), yoko(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    for (int qi = 0; qi < q; qi++) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (tate[c].count(r) > 0) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Destroy the bottom wall up to the first empty cell
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].end()) {
                int bottom = *it;
                while (it != tate[c].end() && *it == bottom) {
                    it++;
                }
                if (it != tate[c].end()) {
                    bottom = *it - 1;
                }
                while (bottom >= 0) {
                    tate[c].erase(bottom);
                    yoko[bottom].erase(c);
                    bottom--;
                }
            }

            // Destroy the top wall down to the first empty cell
            it = tate[c].lower_bound(r);
            if (it == tate[c].end()) {
                it--;
            }
            if (it != tate[c].begin()) {
                int top = *prev(it);
                while (it != tate[c].begin() && *it == top) {
                    it--;
                }
                if (it != tate[c].begin()) {
                    top = *prev(it) + 1;
                }
                while (top < h) {
                    tate[c].erase(top);
                    yoko[top].erase(c);
                    top++;
                }
            }

            // Destroy the right wall left to the first empty cell
            it = yoko[r].lower_bound(c);
            if (it != yoko[r].end()) {
                int right = *it;
                while (it != yoko[r].end() && *it == right) {
                    it++;
                }
                if (it != yoko[r].end()) {
                    right = *it - 1;
                }
                while (right >= 0) {
                    tate[right].erase(r);
                    yoko[r].erase(right);
                    right--;
                }
            }

            // Destroy the left wall right to the first empty cell
            it = yoko[r].lower_bound(c);
            if (it == yoko[r].end()) {
                it--;
            }
            if (it != yoko[r].begin()) {
                int left = *prev(it);
                while (it != yoko[r].begin() && *it == left) {
                    it--;
                }
                if (it != yoko[r].begin()) {
                    left = *prev(it) + 1;
                }
                while (left < w) {
                    tate[left].erase(r);
                    yoko[r].erase(left);
                    left++;
                }
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < w; i++) {
        for (int row : tate[i]) {
            remaining_walls++;
        }
    }
    cout << remaining_walls << endl;

    return 0;
}