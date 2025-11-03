#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(100005); // Max elevation is 10^5

    // Initially, all border cells with elevation <= current sea level (which starts at 0) will sink?
    // But sea level rises each year. Instead, we precompute: when a cell sinks depends on its elevation and connectivity.

    // Correction: We need to simulate rising sea level from year 1 to Y.
    // At year i, sea level is i. Any land with elevation <= i that is connected (via adjacent cells) to the sea will submerge.
    // The key: water flows from borders inward through low-elevation paths.

    // Better approach: process cells in increasing order of elevation.
    // For each elevation e, if a cell has elevation e and is adjacent to already submerged region, it will be submerged when sea level reaches e.

    // Collect all cells by their elevation
    vector<vector<pair<int, int>>> cellsByElev(100005);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cellsByElev[A[i][j]].push_back({i, j});
        }
    }

    int ans = H * W;

    // Use BFS: start from borders and spread inward as sea level rises
    queue<pair<int, int>> bfsQ;

    // At sea level 0, nothing is submerged yet.
    // As sea level increases from 1 to Y, we check which new cells get submerged.

    for (int seaLevel = 1; seaLevel <= Y; seaLevel++) {
        // Add all cells with elevation == seaLevel that are on the border or adjacent to submerged area
        for (auto &cell : cellsByElev[seaLevel]) {
            int x = cell.first;
            int y = cell.second;
            if (!submerged[x][y]) {
                // Check if this cell is on border or adjacent to any submerged cell
                bool canSubmerge = false;
                if (x == 0 || x == H-1 || y == 0 || y == W-1) {
                    canSubmerge = true;
                } else {
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < H && ny < W && submerged[nx][ny]) {
                            canSubmerge = true;
                            break;
                        }
                    }
                }
                if (canSubmerge) {
                    submerged[x][y] = true;
                    ans--;
                    bfsQ.push({x, y});
                }
            }
        }

        // Propagate submersion: any un-submerged neighbor with elevation <= seaLevel gets submerged
        while (!bfsQ.empty()) {
            auto [cx, cy] = bfsQ.front();
            bfsQ.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (!submerged[nx][ny] && A[nx][ny] <= seaLevel) {
                    submerged[nx][ny] = true;
                    ans--;
                    bfsQ.push({nx, ny});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}