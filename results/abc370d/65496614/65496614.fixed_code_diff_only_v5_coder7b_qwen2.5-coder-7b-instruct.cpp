#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> coo(h, vector<bool>(w, true));
    vector<set<int>> row(h), col(w);

    int r, c;

    auto erase_wall = [&](int i, int j) {
        if (i >= 0 && i < h && j >= 0 && j < w) {
            coo[i][j] = false;
            row[i].erase(row[i].find(j));
            col[j].erase(col[j].find(i));
        }
    };

    while (q--) {
        cin >> r >> c;
        --r; --c; // Adjust indices to be zero-based

        if (coo[r][c]) {
            erase_wall(r, c);
        } else {
            for (auto& x : row[r]) {
                if (!coo[x][c]) break;
                erase_wall(x, c);
            }
            for (auto& y : col[c]) {
                if (!coo[r][y]) break;
                erase_wall(r, y);
            }
        }
    }

    int ans = 0;
    for (const auto& row : coo) {
        for (bool val : row) {
            if (val) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}