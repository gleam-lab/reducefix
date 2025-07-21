#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    int broken = 0;

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (map[r][c]) {
            map[r][c] = false;
            ++broken;
        } else {
            // Directions: up, down, left, right
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                while (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                    if (map[nr][nc]) {
                        map[nr][nc] = false;
                        ++broken;
                        break;
                    }
                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }
    }
    cout << (H * W - broken) << endl;
    return 0;
}