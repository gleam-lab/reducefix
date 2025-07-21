#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h), col(w);

    // Initialize all walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        auto it = row[r].find(c);
        if (it != row[r].end()) {
            // Wall already exists here
            row[r].erase(it);
            col[c].erase(col[c].find(r));
        } else {
            // Look in four directions
            vector<pair<int, int>> to_remove;

            // Right
            auto rit = row[r].upper_bound(c);
            if (rit != row[r].end())
                to_remove.emplace_back(r, *rit);

            // Left
            if (rit != row[r].begin()) {
                --rit;
                if (*rit < c)
                    to_remove.emplace_back(r, *rit);
            }

            // Down
            auto cit = col[c].upper_bound(r);
            if (cit != col[c].end())
                to_remove.emplace_back(*cit, c);

            // Up
            if (cit != col[c].begin()) {
                --cit;
                if (*cit < r)
                    to_remove.emplace_back(*cit, c);
            }

            // Remove found walls
            for (auto [x, y] : to_remove) {
                row[x].erase(y);
                col[y].erase(x);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < h; ++i)
        ans += row[i].size();

    cout << ans << "\n";
}