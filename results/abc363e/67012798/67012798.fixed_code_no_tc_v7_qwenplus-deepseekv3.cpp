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

    vector<queue<pair<int, int>>> q(1e5 + 2);
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    int ans = H * W;

    // Initialize the border sections
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                if (!sunk[i][j])
                {
                    q[A[i][j]].push({i, j});
                    sunk[i][j] = true;
                }
            }
        }
    }

    for (int y = 1; y <= Y; y++)
    {
        while (!q[y].empty())
        {
            auto [x, y_] = q[y].front();
            q[y].pop();
            ans--;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y_ + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W || sunk[nx][ny])
                {
                    continue;
                }

                if (A[nx][ny] <= y)
                {
                    sunk[nx][ny] = true;
                    q[y].push({nx, ny});
                }
                else
                {
                    sunk[nx][ny] = true;
                    q[A[nx][ny]].push({nx, ny});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}