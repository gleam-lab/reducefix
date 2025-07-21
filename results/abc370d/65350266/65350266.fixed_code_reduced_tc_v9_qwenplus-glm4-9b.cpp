#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> tate(W); // vertical walls
    vector<set<int>> yoko(H); // horizontal walls

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        if (tate[C].count(R)) {
            tate[C].erase(R);
            yoko[R].erase(C);
        } else {
            // destroy all walls above R for column C
            auto it = tate[C].lower_bound(R);
            if (it != tate[C].end()) {
                int top = *it;
                tate[C].erase(top);
                yoko[top].erase(C);
            }

            // destroy all walls below R for column C
            it = tate[C].upper_bound(R);
            if (it != tate[C].begin()) {
                --it;
                int bottom = *it;
                tate[C].erase(bottom);
                yoko[bottom].erase(C);
            }

            // destroy all walls to the left of C for row R
            it = yoko[R].lower_bound(C);
            if (it != yoko[R].end()) {
                int left = *it;
                yoko[R].erase(left);
                tate[left].erase(R);
            }

            // destroy all walls to the right of C for row R
            it = yoko[R].upper_bound(C);
            if (it != yoko[R].begin()) {
                --it;
                int right = *it;
                yoko[R].erase(right);
                tate[right].erase(R);
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < W; ++i) {
        remaining_walls += tate[i].size();
    }

    cout << remaining_walls << endl;
    return 0;
}