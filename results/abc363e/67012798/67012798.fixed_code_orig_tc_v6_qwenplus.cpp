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

    vector<vector<bool>> island(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> q(100005); // Fixed size to match constraints

    // Initialize with boundary cells that will sink when sea level reaches their elevation
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
            {
                if (A[i][j] <= 100000) // Ensure within bounds
                    q[A[i][j]].push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;

    for (int year = 1; year <= Y; year++)
    {
        // Process all cells that sink at this sea level
        while (!q[year].empty())
        {
            auto [x, y] = q[year].front();
            q[year].pop();

            // Check neighbors and flood them if they're not already sunk and have elevation <= current sea level
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;

                if (island[nx][ny] && A[nx][ny] <= year)
                {
                    island[nx][ny] = false;
                    ans--;
                    // This cell will trigger flooding of its neighbors, so add it to current year's queue
                    q[year].push({nx, ny});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}