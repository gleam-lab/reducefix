#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    set<pair<int, int>> walls;
    long long ans = (long long)h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (walls.count({r, c})) {
            walls.erase({r, c});
            ans++;
        } else {
            walls.insert({r, c});
            ans--;
        }

        // Check four directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && walls.count({nr, nc})) {
                walls.erase({nr, nc});
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}