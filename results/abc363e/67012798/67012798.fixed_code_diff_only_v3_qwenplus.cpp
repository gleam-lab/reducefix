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
    vector<queue<pair<int, int>>> events(100005); // Max elevation is 10^5

    // Initially, all edge cells are exposed to the sea
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                // Schedule submersion at time = A[i][j] (when sea level reaches elevation)
                if (A[i][j] <= 100000)
                    events[A[i][j]].push({i, j});
                submerged[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    // Subtract initially scheduled edge cells
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0 || i == H-1 || j == 0 || j == W-1) && submerged[i][j])
            {
                remaining--;
            }
        }
    }

    // BFS queues for each year
    queue<pair<int, int>> q;

    for (int year = 1; year <= Y; year++)
    {
        // Add all cells that get submerged exactly at this sea level
        while (!events[year].empty())
        {
            auto [x, y] = events[year].front();
            events[year].pop();
            
            if (!submerged[x][y]) {
                submerged[x][y] = true;
                remaining--;
                q.push({x, y});
            }
        }

        // Propagate submersion from newly submerged cells
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

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
                    q.push({nx, ny});
                }
            }
        }

        cout << remaining << '\n';
    }

    return 0;
}