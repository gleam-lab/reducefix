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

    // We'll process cells in increasing order of elevation
    vector<tuple<int, int, int>> cells;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cells.emplace_back(A[i][j], i, j);
        }
    }
    sort(cells.begin(), cells.end());

    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    queue<pair<int, int>> q;
    int ans = H * W;

    int idx = 0;
    for (int year = 1; year <= Y; year++)
    {
        // Add all cells with elevation <= current sea level that haven't been processed
        while (idx < cells.size() && get<0>(cells[idx]) <= year)
        {
            auto [elev, x, y] = cells[idx];
            if (!submerged[x][y])
            {
                // If this cell is on the border or adjacent to a submerged cell, it will sink
                bool borders_water = (x == 0 || x == H-1 || y == 0 || y == W-1);
                bool adjacent_submerged = false;
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && submerged[nx][ny])
                    {
                        adjacent_submerged = true;
                        break;
                    }
                }
                
                if (borders_water || adjacent_submerged)
                {
                    submerged[x][y] = true;
                    q.push({x, y});
                    ans--;
                }
            }
            idx++;
        }

        // Flood fill from newly submerged cells
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W || submerged[nx][ny])
                    continue;

                // If adjacent cell has elevation <= current sea level, it also sinks
                if (A[nx][ny] <= year)
                {
                    submerged[nx][ny] = true;
                    q.push({nx, ny});
                    ans--;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}