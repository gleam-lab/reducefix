#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_H = 4e5 + 10;
const int MAX_W = 4e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> map(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> q(4);
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if(map[r][c]) {
            map[r][c] = false;
        } else {
            for(int i = 0; i < 4; ++i) {
                int x = r + dir[i].first, y = c + dir[i].second;
                while(x >= 0 && x < H && y >= 0 && y < W) {
                    if(map[x][y]) {
                        map[x][y] = false;
                        break;
                    }
                    x += dir[i].first;
                    y += dir[i].second;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H; ++i) 
        for(int j = 0; j < W; ++j) 
            if(map[i][j]) ++ans;

    cout << ans << '\n';
    return 0;
}