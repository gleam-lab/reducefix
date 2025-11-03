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
    vector<queue<pair<int, int>>> q(Y + 1); // Only need up to Y

    // Initialize: all border cells are adjacent to sea
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                // Will be processed when sea level reaches A[i][j]
                if (A[i][j] <= Y)
                {
                    q[A[i][j]].push({i, j});
                }
                submerged[i][j] = true;
            }
        }
    }

    int remaining = H * W;

    // For years where no initial border cell gets submerged, we still need output
    for (int year = 1; year <= Y; year++)
    {
        queue<pair<int, int>> bfs;
        
        // Add all cells whose elevation equals current sea level and are on the "frontier"
        while (!q[year].empty())
        {
            auto [x, y] = q[year].front();
            q[year].pop();
            // Only process if not already submerged by earlier propagation
            if (submerged[x][y] && A[x][y] == year)
            {
                bfs.push({x, y});
            }
        }

        // Flood fill from all starting points at this sea level
        while (!bfs.empty())
        {
            auto [x, y] = bfs.front();
            bfs.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;

                if (!submerged[nx][ny] && A[nx][ny] <= year)
                {
                    submerged[nx][ny] = true;
                    remaining--;
                    bfs.push({nx, ny});
                }
            }
        }

        cout << remaining << '\n';
    }

    return 0;
}