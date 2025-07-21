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

    // Initially all land is above sea level
    vector<vector<bool>> island(H, vector<bool>(W, true));

    // Prepare a map of height -> cells at that height
    unordered_map<int, vector<pair<int, int>>> heightMap;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            heightMap[A[i][j]].push_back({i, j});
        }
    }

    // For each year, we simulate the sinking
    int remaining = H * W;
    vector<int> result(Y + 1); // result[i] = area after i years

    // We will process heights in increasing order
    vector<int> sortedHeights;
    for (auto &[h, _] : heightMap)
        sortedHeights.push_back(h);
    sort(sortedHeights.begin(), sortedHeights.end());

    // To keep track of visited cells
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // BFS queue for sinking process
    queue<pair<int, int>> q;

    int currentYear = 0;
    int idx = 0; // index for sortedHeights

    while (currentYear <= Y)
    {
        // Process all heights that are <= currentYear
        while (idx < sortedHeights.size() && sortedHeights[idx] <= currentYear)
        {
            int h = sortedHeights[idx++];
            for (auto [x, y] : heightMap[h])
            {
                if (!visited[x][y] && (x == 0 || x == H-1 || y == 0 || y == W-1))
                {
                    // Start BFS from this cell
                    q.push({x, y});
                    visited[x][y] = false;
                    remaining--;
                }
            }
        }

        // Now do BFS to find all connected cells that should sink
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;

                if (visited[nx][ny] && A[nx][ny] <= currentYear)
                {
                    visited[nx][ny] = false;
                    remaining--;
                    q.push({nx, ny});
                }
            }
        }

        result[currentYear] = remaining;
        currentYear++;
    }

    // Output results for years 1 to Y
    for (int i = 1; i <= Y; i++)
        cout << result[i] << "\n";

    return 0;
}