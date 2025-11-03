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
    vector<queue<pair<int, int>>> q(Y + 1); // Only create queues up to Y
    
    // Initialize the initial sinking at year corresponding to border cell's elevation
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
            {
                int year = A[i][j]; // This cell sinks when sea level reaches its elevation
                if (year <= Y) {
                    q[year].push({i, j});
                    island[i][j] = false;
                }
            }
        }
    }

    int ans = H * W;

    for (int year = 1; year <= Y; year++)
    {
        while (!q[year].empty())
        {
            auto [x, y] = q[year].front();
            q[year].pop();

            ans--;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                {
                    continue;
                }

                if (island[nx][ny])
                {
                    int sink_year = A[nx][ny];
                    if (sink_year <= year) {
                        // Sinks now
                        q[year].push({nx, ny});
                        island[nx][ny] = false;
                    } else {
                        // Will sink in the future
                        if (sink_year <= Y) {
                            q[sink_year].push({nx, ny});
                            island[nx][ny] = false;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}