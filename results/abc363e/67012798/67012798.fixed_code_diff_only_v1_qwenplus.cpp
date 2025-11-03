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
    vector<vector<pair<int, int>>> events(1e5 + 5); // Store cells that become submerged at sea level = elevation

    // Initially, all border cells will eventually be submerged when sea level reaches their elevation
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                events[A[i][j]].push_back({i, j});
            }
        }
    }

    int remaining = H * W;

    // We'll use BFS to simulate the flooding process properly
    queue<pair<int, int>> q;

    for (int year = 1; year <= Y; year++)
    {
        // Add all cells that start getting flooded at this sea level
        for (auto &cell : events[year])
        {
            int x = cell.first, y = cell.second;
            if (!submerged[x][y] && A[x][y] <= year)
            {
                submerged[x][y] = true;
                q.push({x, y});
                remaining--;
            }
        }

        // Propagate the flooding from newly submerged cells
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

                if (!submerged[nx][ny] && A[nx][ny] <= year)
                {
                    submerged[nx][ny] = true;
                    q.push({nx, ny});
                    remaining--;
                }
            }
        }

        cout << remaining << '\n';
    }

    return 0;
}