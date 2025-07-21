#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> tate(h + 1); // We use h+1 to avoid boundary issues
    vector<set<int>> yoko(w + 1); // We use w+1 to avoid boundary issues
    vector<vector<int>> walls(H * W); // To keep track of walls at each cell

    // Initialize walls
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            walls[i * W + j].push_back(i);
            walls[i * W + j].push_back(j);
        }
    }

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        auto it = walls[r * W + c].begin();
        if (it != walls[r * W + c].end() && *it == c) {
            // Destroy the wall at (r, c)
            walls[r * W + c].erase(it);
            yoko[r].erase(c);
            tate[c].erase(r);
        } else {
            // Destroy walls horizontally
            for (auto& r : walls) {
                auto j = find(r.begin(), r.end(), c);
                if (j != r.end()) r.erase(j);
            }
            // Destroy walls vertically
            for (auto& y : yoko) {
                auto i = find(y.begin(), y.end(), r);
                if (i != y.end()) y.erase(i);
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            remaining_walls += walls[i * W + j].size();
        }
    }

    cout << remaining_walls << endl;

    return 0;
}