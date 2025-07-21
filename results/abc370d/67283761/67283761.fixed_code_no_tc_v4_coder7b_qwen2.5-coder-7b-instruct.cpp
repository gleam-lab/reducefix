#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));

    unordered_set<int> walls;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            walls.insert(i * W + j);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        int idx = r * W + c;

        if (walls.find(idx) != walls.end()) {
            walls.erase(idx);
        } else {
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 || dc == 0) {
                        int rr = r + dr, cc = c + dc;
                        while (rr >= 0 && rr < H && cc >= 0 && cc < W) {
                            int nidx = rr * W + cc;
                            if (walls.find(nidx) != walls.end()) {
                                walls.erase(nidx);
                                break;
                            }
                            rr += dr, cc += dc;
                        }
                    }
                }
            }
        }
    }

    cout << walls.size() << endl;

    return 0;
}