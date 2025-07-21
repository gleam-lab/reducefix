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

    // Initialize island as all land
    vector<vector<bool>> island(H, vector<bool>(W, true));

    // Use a queue for BFS per year
    vector<pair<int, int>> borders;

    // Identify and enqueue border cells
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                borders.emplace_back(i, j);
            }
        }
    }

    // Sort the borders by elevation
    sort(borders.begin(), borders.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return A[a.first][a.second] < A[b.first][b.second];
    });

    int totalArea = H * W;
    int idx = 0;  // Index for processing borders

    // For each year, simulate the sea level rise
    for (int year = 1; year <= Y; ++year)
    {
        while (idx < borders.size() && A[borders[idx].first][borders[idx].second] <= year)
        {
            int x = borders[idx].first;
            int y = borders[idx].second;
            ++idx;

            if (!island[x][y]) continue;

            island[x][y] = false;
            --totalArea;

            // Flood-fill from this point
            queue<pair<int, int>> q;
            q.emplace(x, y);

            while (!q.empty())
            {
                auto [cx, cy] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d)
                {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < H && ny < W && island[nx][ny] && A[nx][ny] <= year)
                    {
                        island[nx][ny] = false;
                        --totalArea;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        cout << totalArea << '\n';
    }

    return 0;
}