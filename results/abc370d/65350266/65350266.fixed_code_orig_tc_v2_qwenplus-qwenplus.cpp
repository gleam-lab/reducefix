#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // For each row and column, track the set of remaining walls
    vector<set<int>> rows(H), cols(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // If there is a wall at this position
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int y = *it;
                rows[y].erase(c);
                cols[c].erase(it);
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                int y = *it;
                rows[y].erase(c);
                cols[c].erase(it);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int x = *it;
                cols[x].erase(r);
                rows[r].erase(it);
            }

            // Right
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                int x = *it;
                cols[x].erase(r);
                rows[r].erase(it);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i)
        ans += rows[i].size();
    cout << ans << "\n";
    return 0;
}