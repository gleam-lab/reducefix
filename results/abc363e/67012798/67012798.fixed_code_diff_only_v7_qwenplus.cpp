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
    queue<pair<int, int>> q;
    
    // Initially, all border cells that are <= current sea level (which starts at 0) will be submerged?
    // But sea level rises each year. We need to simulate year by year.
    // Instead: For each year i (sea level = i), we want to submerge any cell with elevation <= i
    // that is connected to the sea via already submerged cells.

    // Better approach: Use a priority queue or process by elevation.
    // Since Y can be up to 1e5 and H, W up to 1000, total cells 1e6, we need efficient method.

    // Alternate idea: Process cells in increasing order of elevation.
    // Store all cells and sort by elevation. Then for each year, add all cells with elevation == year
    // that are adjacent to already submerged region? But connectivity matters.

    // Actually, use multi-source BFS starting from borders, processing in order of elevation.
    // We maintain a min-heap (priority_queue) of cells that can be submerged, keyed by elevation.

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Start with all border cells
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

    int remaining = H * W;
    vector<int> ans(Y + 1, remaining); // ans[i] = area after i years

    // Process cells in order of increasing elevation
    while (!pq.empty())
    {
        auto [elev, x, y] = pq.top();
        pq.pop();

        // This cell gets submerged when sea level reaches 'elev'
        if (elev <= Y)
        {
            // All years from elev onward lose this cell
            for (int year = elev; year <= Y; year++)
            {
                ans[year]--;
            }
        }

        // Propagate to neighbors
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || submerged[nx][ny])
                continue;

            submerged[nx][ny] = true;
            pq.push({A[nx][ny], nx, ny});
        }
    }

    // Output for each year
    for (int i = 1; i <= Y; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}