#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    vector<vector<Point>> prev(H, vector<Point>(W, {-1, -1}));

    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if(map[r][c]) {
            map[r][c] = false;
        } else {
            queue<Point> q;
            q.push({r, c});

            while(!q.empty()) {
                Point p = q.front();
                q.pop();

                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(dx == 0 && dy == 0 || abs(dx) != abs(dy)) continue;

                        int nx = p.x + dx, ny = p.y + dy;

                        if(nx >= 0 && nx < H && ny >= 0 && ny < W && map[nx][ny]) {
                            map[nx][ny] = false;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(map[i][j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}