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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    vector<vector<pair<int, int>>> elevations(100001); // Max elevation is 10^5

    // Group all cells by their elevation
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            elevations[A[i][j]].push_back({i, j});
        }
    }

    int remaining = H * W;

    // We'll use a queue for BFS when processing sinking
    queue<pair<int, int>> q;

    for (int year = 1; year <= Y; year++)
    {
        // Add all cells with elevation == year that haven't sunk yet
        for (auto [x, y] : elevations[year])
        {
            if (!sunk[x][y])
            {
                // Check if this cell is connected to the sea (either on border or adjacent to already sunk cell)
                bool connected_to_sea = false;
                
                if (x == 0 || x == H-1 || y == 0 || y == W-1)
                {
                    connected_to_sea = true;
                }
                else
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < H && ny < W && sunk[nx][ny])
                        {
                            connected_to_sea = true;
                            break;
                        }
                    }
                }

                if (connected_to_sea)
                {
                    sunk[x][y] = true;
                    q.push({x, y});
                    remaining--;
                }
            }
        }

        // Propagate the sinking: any adjacent cell with elevation <= current year will also sink
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W || sunk[nx][ny])
                    continue;

                if (A[nx][ny] <= year)
                {
                    sunk[nx][ny] = true;
                    q.push({nx, ny});
                    remaining--;
                }
            }
        }

        cout << remaining << '\n';
    }

    return 0;
}