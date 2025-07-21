#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row(W), col(H);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    ll totalWalls = H * W;

    auto removeWall = [&](int r, int c) {
        row[c].erase(r);
        col[r].erase(c);
        totalWalls--;
    };

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at the bomb position, destroy it and continue
        if (row[C].count(R)) {
            removeWall(R, C);
            continue;
        }

        // Up
        auto it = row[C].lower_bound(R);
        if (it != row[C].begin()) {
            int u = *(--it);
            removeWall(u, C);
        }

        // Down
        it = row[C].lower_bound(R);
        if (it != row[C].end()) {
            int d = *it;
            removeWall(d, C);
        }

        // Left
        auto jt = col[R].lower_bound(C);
        if (jt != col[R].begin()) {
            int l = *(--jt);
            removeWall(R, l);
        }

        // Right
        jt = col[R].lower_bound(C);
        if (jt != col[R].end()) {
            int r = *jt;
            removeWall(R, r);
        }
    }

    cout << totalWalls << endl;
    return 0;
}