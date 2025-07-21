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
    vector<queue<pair<int, int>>> q(Y + 2);  // Changed to Y+2 to avoid index issues

    // Initialize the queue with border cells
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                int year = A[i][j];
                if (year > Y) continue;  // Skip if it won't sink within Y years
                q[year].push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;

    // Process all years up to Y
    for (int year = 1; year <= Y; ++year)
    {
        queue<pair<int, int>> processQ = q[year];

        while (!processQ.empty())
        {
            auto [x, y] = processQ.front();
            processQ.pop();
            ans--;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;

                if (island[nx][ny] && A[nx][ny] <= Y)
                {
                    island[nx][ny] = false;
                    // If this cell will be processed in a future year, enqueue it there
                    if (A[nx][ny] > year)
                    {
                        q[A[nx][ny]].push({nx, ny});
                    }
                    else
                    {
                        processQ.push({nx, ny});  // Sink now if elevation <= current year
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}