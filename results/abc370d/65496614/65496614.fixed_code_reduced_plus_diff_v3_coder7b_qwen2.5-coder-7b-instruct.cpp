#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h + 2, vector<bool>(w + 2, true));
    vector<set<int>> rows(h + 2), cols(w + 2);

    for (int i = 0; i <= h + 1; ++i) {
        rows[i].insert(0);
        rows[i].insert(w + 1);
    }
    for (int j = 0; j <= w + 1; ++j) {
        cols[j].insert(0);
        cols[j].insert(h + 1);
    }

    auto erase_wall = [&](int x, int y) {
        if (!grid[x][y]) return;
        grid[x][y] = false;
        rows[x].erase(rows[x].find(y));
        cols[y].erase(cols[y].find(x));
    };

    auto place_bomb = [&](int x, int y) {
        if (grid[x][y]) {
            erase_wall(x, y);
            return;
        }

        auto upper_it = rows[x].lower_bound(y);
        if (upper_it != rows[x].begin()) {
            --upper_it;
            erase_wall(*upper_it, x);
        }
        upper_it = rows[x].upper_bound(y);
        if (upper_it != rows[x].end()) {
            erase_wall(*upper_it, x);
        }

        auto left_it = cols[y].lower_bound(x);
        if (left_it != cols[y].begin()) {
            --left_it;
            erase_wall(x, *left_it);
        }
        left_it = cols[y].upper_bound(x);
        if (left_it != cols[y].end()) {
            erase_wall(x, *left_it);
        }
    };

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        place_bomb(r, c);
    }

    int count = 0;
    for (const auto& row : rows) {
        count += row.size() - 2;
    }

    cout << count << '\n';
    return 0;
}