#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // tate[c]: set of rows in column c that still have a wall
    // yoko[r]: set of columns in row r that still have a wall
    vector<set<int>> tate(W), yoko(H);

    // Initialize all walls present
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            tate[c].insert(r);
            yoko[r].insert(c);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check if there's a wall at the current position
        if (tate[C].count(R)) {
            // Destroy wall at (R, C)
            tate[C].erase(R);
            yoko[R].erase(C);
        } else {
            // Up direction
            auto it = tate[C].lower_bound(R);
            if (it != tate[C].begin()) {
                it--;
                int r = *it;
                tate[C].erase(r);
                yoko[r].erase(C);
            }

            // Down direction
            it = tate[C].lower_bound(R);
            if (it != tate[C].end()) {
                int r = *it;
                tate[C].erase(r);
                yoko[r].erase(C);
            }

            // Left direction
            auto jt = yoko[R].lower_bound(C);
            if (jt != yoko[R].begin()) {
                jt--;
                int c = *jt;
                yoko[R].erase(c);
                tate[c].erase(R);
            }

            // Right direction
            jt = yoko[R].lower_bound(C);
            if (jt != yoko[R].end()) {
                int c = *jt;
                yoko[R].erase(c);
                tate[c].erase(R);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int c = 0; c < W; ++c) {
        ans += tate[c].size();
    }
    cout << ans << '\n';

    return 0;
}