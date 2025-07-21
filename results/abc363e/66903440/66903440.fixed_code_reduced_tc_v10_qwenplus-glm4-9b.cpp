#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int x, y;
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> is_sunk(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    queue<Pair> q;
    int ans = H * W;

    // Initialize the queue with edges of the island
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.push({i, j});
            }
        }
    }

    // Perform BFS to find initial sunk sections
    while (!q.empty()) {
        Pair p = q.front();
        q.pop();
        if (!is_sunk[p.x][p.y] && A[p.x][p.y] <= q.size()) {
            is_sunk[p.x][p.y] = true;
            ans--;
            for (int k = 0; k < 4; k++) {
                if (p.x + dx[k] >= 0 && p.x + dx[k] < H && p.y + dy[k] >= 0 && p.y + dy[k] < W) {
                    q.push({p.x + dx[k], p.y + dy[k]});
                }
            }
        }
    }

    // Process each year's sea level rise
    for (int y = 1; y <= Y; y++) {
        queue<Pair> new_q;
        // Propagate sinking sections
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (is_sunk[i][j] && A[i][j] - y <= q.size()) {
                    new_q.push({i, j});
                    is_sunk[i][j] = false;
                    for (int k = 0; k < 4; k++) {
                        if (i + dx[k] >= 0 && i + dx[k] < H && j + dy[k] >= 0 && j + dy[k] < W) {
                            new_q.push({i + dx[k], j + dy[k]});
                        }
                    }
                }
            }
        }
        // Perform BFS to find newly sunk sections
        while (!new_q.empty()) {
            Pair p = new_q.front();
            new_q.pop();
            if (!is_sunk[p.x][p.y] && A[p.x][p.y] <= q.size()) {
                is_sunk[p.x][p.y] = true;
                ans--;
                for (int k = 0; k < 4; k++) {
                    if (p.x + dx[k] >= 0 && p.x + dx[k] < H && p.y + dy[k] >= 0 && p.y + dy[k] < W) {
                        new_q.push({p.x + dx[k], p.y + dy[k]});
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}