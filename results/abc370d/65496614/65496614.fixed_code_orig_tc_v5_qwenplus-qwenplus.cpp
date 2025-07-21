#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    const int MAX = max(H, W) + 2;

    vector<set<int>> row(H + 2), col(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    vb alive(H * W + 5, true);

    auto get_index = [&](int x, int y) { return (x - 1) * W + (y - 1); };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        int idx = get_index(r, c);
        if (alive[idx]) {
            // Bomb at (r,c) has wall, destroy it
            alive[idx] = false;
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Look in four directions and destroy first walls found
            for (int d = 0; d < 4; ++d) {
                int nr = r, nc = c;
                while (true) {
                    nr += dx[d];
                    nc += dy[d];
                    if (nr < 1 || nr > H || nc < 1 || nc > W) break;
                    int ni = get_index(nr, nc);
                    if (alive[ni]) {
                        alive[ni] = false;
                        row[nr].erase(nc);
                        col[nc].erase(nr);
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (alive[get_index(i, j)]) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}