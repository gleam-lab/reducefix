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

    // Instead of pre-adding all border cells to queues, we'll simulate year by year
    // and use a priority queue (or process by elevation) to ensure correct flooding order.
    // The key issue: water spreads from any submerged cell to adjacent cells with elevation <= current sea level.
    // We need to simulate the rising sea level and flood cells in the correct order.

    // We'll use a BFS that starts from the borders and processes cells in increasing order of elevation.
    // Use a min-heap (priority_queue) to process cells with smallest elevation first.

    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Initialize: all border cells are exposed to sea
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                pq.push({A[i][j], i, j});
                submerged[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y + 1); // Store result for each year

    // Process cells in order of increasing elevation
    while (!pq.empty())
    {
        auto [elev, x, y] = pq.top();
        pq.pop();

        // This cell gets submerged when sea level reaches 'elev'
        // But we record it only once
        if (elev > Y) continue; // Only care up to year Y

        // All cells with elevation <= current sea level that are connected will be flooded
        // We already marked this as submerged when added

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

            if (!submerged[nx][ny])
            {
                submerged[nx][ny] = true;
                pq.push({A[nx][ny], nx, ny});
            }
        }
    }

    // Now, count how many cells remain unsubmerged at each sea level
    vector<int> submergedCount(Y + 1, 0);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (submerged[i][j] && A[i][j] <= Y)
            {
                submergedCount[A[i][j]]++;
            }
            else if (submerged[i][j] && A[i][j] > Y)
            {
                // Count in the last possible year
                submergedCount[Y]++;
            }
        }
    }

    // Actually, the above approach has flaws. Let's fix:

    // Correct approach:
    // At year i, sea level = i
    // A cell is submerged if it is connected (via other submerged cells) to the border
    // and its path has all elevations <= i.
    // So we want to know, for each year i, how many cells have been flooded by then.

    // Instead, let's do multi-source Dijkstra-like algorithm where "time" of submersion
    // of a cell is the minimum maximum elevation along any path from border to that cell.

    // Reset
    vector<vector<int>> submergenceYear(H, vector<int>(W, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> dijkstra_pq;

    // All border cells submerge at year = A[i][j]
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                submergenceYear[i][j] = A[i][j];
                dijkstra_pq.push({A[i][j], i, j});
            }
        }
    }

    while (!dijkstra_pq.empty())
    {
        auto [year, x, y] = dijkstra_pq.top();
        dijkstra_pq.pop();

        if (year != submergenceYear[x][y]) continue;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

            int newYear = max(year, A[nx][ny]); // The submergence year is the max elevation on the path
            if (newYear < submergenceYear[nx][ny])
            {
                submergenceYear[nx][ny] = newYear;
                dijkstra_pq.push({newYear, nx, ny});
            }
        }
    }

    // Count remaining area for each year
    vector<int> remaining(Y + 1);
    for (int i = 1; i <= Y; i++)
    {
        remaining[i] = H * W;
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int t = submergenceYear[i][j];
            if (t <= Y)
            {
                for (int y = t; y <= Y; y++)
                {
                    remaining[y]--;
                }
            }
        }
    }

    // But this is O(H*W*Y) which is too slow (up to 10^9)

    // Instead, use difference array
    vector<int> diff(Y + 2, 0); // diff[i] += x means from year i onward, subtract x more
    int totalCells = H * W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int t = submergenceYear[i][j];
            if (t <= Y)
            {
                diff[t]++;
            }
            // If t > Y, it never submerges within our observation
        }
    }

    int submergedSoFar = 0;
    for (int i = 1; i <= Y; i++)
    {
        submergedSoFar += diff[i];
        cout << totalCells - submergedSoFar << endl;
    }

    return 0;
}