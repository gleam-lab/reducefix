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

    // Create a grid to track whether a cell is submerged
    vector<vector<bool>> submerged(H, vector<bool>(W, false));

    // Use a priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Mark border cells and add them to the queue
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                pq.emplace(A[i][j], i, j);
                submerged[i][j] = true;
            }
        }
    }

    // We'll simulate up to Y years
    vector<int> result(Y + 2); // result[year]
    result[0] = H * W;

    // Track how many cells have been submerged at each year
    vector<int> submerge_count(Y + 2, 0);

    while (!pq.empty())
    {
        auto [elevation, x, y] = pq.top();
        pq.pop();

        // If this cell was already submerged at an earlier year, skip it
        if (!submerged[x][y])
        {
            submerged[x][y] = true;
            submerge_count[elevation]++;
        }

        // Try to spread to neighbors if they can be submerged
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < H && ny < W && !submerged[nx][ny] && A[nx][ny] <= elevation)
            {
                pq.emplace(A[nx][ny], nx, ny);
                submerged[nx][ny] = true;
                submerge_count[A[nx][ny]]++;
            }
        }
    }

    // Build final answer
    int remaining = H * W;
    for (int i = 1; i <= Y; ++i)
    {
        remaining -= submerge_count[i];
        cout << remaining << "\n";
    }

    return 0;
}