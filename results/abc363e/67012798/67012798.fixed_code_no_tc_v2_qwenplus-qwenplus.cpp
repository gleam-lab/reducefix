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

    // Initialize the island map
    vector<vector<bool>> is_land(H, vector<bool>(W, true));

    // For each year, store cells that will sink in a list
    vector<vector<pair<int, int>>> to_sink(Y + 2);  // up to Y+1

    // Group border cells by their elevation
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                to_sink[A[i][j]].emplace_back(i, j);
            }
        }
    }

    // BFS processing for sinking
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // We'll process from lowest sea level to highest
    for (int y = 1; y <= Y; ++y)
    {
        // Add new cells to sink this year
        for (auto [x, y_coord] : to_sink[y])
        {
            if (is_land[x][y_coord] && !visited[x][y_coord])
            {
                q.push({x, y_coord});
                visited[x][y_coord] = true;
            }
        }

        while (!q.empty())
        {
            auto [x, y_coord] = q.front();
            q.pop();

            if (!is_land[x][y_coord]) continue;
            
            is_land[x][y_coord] = false;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y_coord + dy[d];

                if (nx >= 0 && ny >= 0 && nx < H && ny < W && is_land[nx][ny])
                {
                    if (A[nx][ny] <= y)
                    {
                        q.push({nx, ny});
                    }
                    else
                    {
                        // Schedule sinking for future years
                        if (A[nx][ny] <= Y)
                            to_sink[A[nx][ny]].emplace_back(nx, ny);
                    }
                }
            }
        }

        // Count remaining land cells
        int remaining = 0;
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                if (is_land[i][j])
                    ++remaining;
            }
        }
        cout << remaining << "\n";
    }

    return 0;
}