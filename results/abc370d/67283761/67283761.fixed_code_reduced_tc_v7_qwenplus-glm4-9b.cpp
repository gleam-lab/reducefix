#include <iostream>
#include <vector>

using namespace std;

struct Query {
    int r, c;
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> map(H, vector<bool>(W, true));
    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].r >> queries[i].c;
    }

    // Check each query and process as described
    for (const auto& query : queries) {
        int r = query.r - 1;
        int c = query.c - 1;

        if (map[r][c]) {
            // If there's a wall at the location, it is destroyed
            map[r][c] = false;
        } else {
            // If there's no wall at the location, destroy walls around it
            bool destroyed = false;
            for (int dr = -1; dr <= 1; ++dr) {
                int nr = r + dr;
                if (nr < 0 || nr >= H) continue;
                map[nr][c] = false;
                destroyed = true;
            }
            for (int dc = -1; dc <= 1; ++dc) {
                int nc = c + dc;
                if (nc < 0 || nc >= W) continue;
                map[r][nc] = false;
                destroyed = true;
            }
            if (!destroyed) {
                // If no wall was found at the exact location, destroy walls in all four directions
                for (int d = 0; d < 4; ++d) {
                    int dr = (d == 0 || d == 2) ? -1 : 1;
                    int dc = (d == 1 || d == 3) ? -1 : 1;
                    int r1 = r, c1 = c;
                    while (true) {
                        r1 += dr;
                        c1 += dc;
                        if (r1 < 0 || r1 >= H || c1 < 0 || c1 >= W || !map[r1][c1]) break;
                        map[r1][c1] = false;
                    }
                }
            }
        }
    }

    // Count the remaining walls and print the result
    int remainingWalls = 0;
    for (const auto& row : map) {
        for (bool wall : row) {
            if (wall) ++remainingWalls;
        }
    }
    cout << remainingWalls << endl;

    return 0;
}