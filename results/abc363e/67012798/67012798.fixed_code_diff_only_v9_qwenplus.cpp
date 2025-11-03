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
    vector<vector<pair<int, int>>> to_process(Y + 1); // Only need up to Y

    // Add all border cells to be processed at their elevation year
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                if (A[i][j] <= Y)
                    to_process[A[i][j]].push_back({i, j});
                else
                    to_process[Y].push_back({i, j}); // Will be handled at year Y if higher
            }
        }
    }

    int remaining = H * W;

    // Use a queue for BFS propagation during each year
    queue<pair<int, int>> q;

    for (int year = 1; year <= Y; year++)
    {
        // Add initial border cells that get submerged this year
        for (auto &cell : to_process[year])
        {
            int x = cell.first, y = cell.second;
            if (!submerged[x][y] && A[x][y] <= year)
            {
                submerged[x][y] = true;
                q.push({x, y});
                remaining--;
            }
        }

        // Propagate flooding from all currently submerged cells using BFS
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (submerged[nx][ny]) continue;
                if (A[nx][ny] > year) continue; // Too high to sink yet

                submerged[nx][ny] = true;
                q.push({nx, ny});
                remaining--;
            }
        }

        cout << remaining << '\n';
    }

    return 0;
}