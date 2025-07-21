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
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> A[i][j];
        }
    }

    // Initialize island map: true means still land
    vector<vector<bool>> is_land(H, vector<bool>(W, true));

    // Map of cells that will sink at each year
    vector<vector<pair<int, int>>> to_sink(Y + 2); // index by year

    // Queue for BFS processing per year
    queue<pair<int, int>> q;

    // Mark boundary cells and add to queue if they sink in their own year
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                int year = A[i][j];
                if (year <= Y)
                {
                    to_sink[year].emplace_back(i, j);
                }
                is_land[i][j] = false;
            }
        }
    }

    // Process each year incrementally
    int remaining = H * W;

    // To store the total number of sunken cells up to each year
    vector<int> sunk_by_year(Y + 1, 0);
    vector<int> cum_sunk(Y + 2, 0); // cumulative sunk by year

    for (int year = 1; year <= Y; ++year)
    {
        // Add new sinking cells for this year
        for (auto [x, y] : to_sink[year])
        {
            if (is_land[x][y])
            {
                is_land[x][y] = false;
                q.emplace(x, y);
                sunk_by_year[year]++;
                remaining--;
            }
        }

        // BFS to propagate sinking
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && is_land[nx][ny])
                {
                    int cell_year = A[nx][ny];
                    if (cell_year <= Y && cell_year > year)
                    {
                        // Sink now but not originally scheduled
                        to_sink[cell_year].emplace_back(nx, ny);
                    }
                    if (cell_year <= Y)
                    {
                        is_land[nx][ny] = false;
                        q.emplace(nx, ny);
                        sunk_by_year[year]++;
                        remaining--;
                    }
                }
            }
        }

        cum_sunk[year] = cum_sunk[year - 1] + sunk_by_year[year];
        cout << (H * W - cum_sunk[year]) << endl;
    }

    return 0;
}