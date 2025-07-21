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

    // Use a single queue instead of vector of queues to avoid high memory usage
    vector<vector<bool>> island(H, vector<bool>(W, true));
    queue<pair<int, int>> q;

    // Initialize the queue with border cells
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1))
            {
                q.emplace(i, j);
                island[i][j] = false;
            }
        }
    }

    int totalArea = H * W;
    vector<int> result(Y + 1);  // Store results for each year
    result[0] = totalArea;

    // Create a grid to keep track of current processing level
    vector<vector<int>> seaLevel(H, vector<int>(W, INT_MAX));

    // BFS to simulate erosion process over time
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || !island[nx][ny])
                continue;

            int currSeaLevel = max(A[x][y], A[nx][ny]);

            if (currSeaLevel > Y)
                continue;

            island[nx][ny] = false;
            q.emplace(nx, ny);
            A[nx][ny] = currSeaLevel;  // Update value to prevent reprocessing
        }
    }

    // Now, compute how many cells remain after each year
    vector<int> areaCount(Y + 2, 0);  // Count of cells eroded at each year

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (A[i][j] <= Y)
                areaCount[A[i][j]]++;
        }
    }

    // Compute cumulative sum
    for (int i = 1; i <= Y; ++i)
    {
        areaCount[i] += areaCount[i - 1];
        cout << totalArea - areaCount[i] << '\n';
    }

    return 0;
}