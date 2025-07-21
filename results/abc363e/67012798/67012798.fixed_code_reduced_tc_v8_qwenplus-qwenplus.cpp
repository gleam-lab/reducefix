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

    // Total area initially
    int remaining = H * W;

    // Grid to track whether a cell is still above sea level
    vector<vector<bool>> aboveWater(H, vector<bool>(W, true));

    // Priority queue to simulate the erosion process (min-heap by elevation)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Initialize: mark border cells as eroded and add their neighbors if affected
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                aboveWater[i][j] = false;
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    // Process up to Y years
    vector<int> results(Y + 2); // Store results for 1-based index

    // To handle each year's result correctly
    int currentYear = 0;
    for (int year = 1; year <= Y; ++year)
    {
        // While there are cells that sink at this year or earlier
        while (!pq.empty() && get<0>(pq.top()) <= year)
        {
            auto [elev, x, y] = pq.top();
            pq.pop();

            // This cell sinks
            remaining--;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < H && ny < W && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }

        results[year] = remaining;
    }

    // Output results from year 1 to Y
    for (int year = 1; year <= Y; ++year)
    {
        cout << results[year] << '\n';
    }

    return 0;
}