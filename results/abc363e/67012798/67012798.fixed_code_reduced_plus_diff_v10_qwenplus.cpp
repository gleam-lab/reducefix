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
    vector<queue<pair<int, int>>> q(Y + 1); // Only allocate queues for years we need
    
    // Initialize with border cells that will sink at their elevation year
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
            {
                int year = min(A[i][j], Y); // Don't add to queue beyond Y
                q[year].push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;

    for (int i = 1; i <= Y; i++)
    {
        while (!q[i].empty())
        {
            auto [x, y] = q[i].front();
            q[i].pop();

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
                    island[nx][ny] = false;
                    int next_year = min(A[nx][ny], Y); // Sink at min(elevation, Y)
                    if (next_year >= i) {
                        q[next_year].push({nx, ny});
                    } else {
                        // If this cell should have sunk earlier, process immediately
                        q[i].push({nx, ny});
                    }
                }
            }
            
            ans--;
        }

        cout << ans << '\n';
    }

    return 0;
}