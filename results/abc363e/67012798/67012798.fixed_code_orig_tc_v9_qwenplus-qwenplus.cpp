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

    // Prepare initial border cells to be flooded
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && island[i][j])
            {
                q.emplace(i, j);
                island[i][j] = false;
            }
        }
    }

    // Process the flood using BFS
    auto process_year = [&](int year, queue<pair<int, int>>& current_q) -> int
    {
        int removed = 0;
        while (!current_q.empty())
        {
            auto [x, y] = current_q.front();
            current_q.pop();
            removed++;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < H && ny < W && island[nx][ny] && A[nx][ny] > year)
                {
                    island[nx][ny] = false;
                    current_q.push({nx, ny});
                }
            }
        }
        return removed;
    };

    // For each cell, store the year when it gets flooded
    vector<vector<int>> flood_year(H, vector<int>(W, Y + 1)); // default is never flooded

    // We'll use a priority queue to process cells in increasing order of their elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Initialize all cells into the priority queue with their elevation
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            pq.emplace(A[i][j], i, j);
        }
    }

    // Keep track of visited cells to avoid reprocessing
    vector<vector<bool>> processed(H, vector<bool>(W, false));

    // Use a queue for BFS during processing
    queue<pair<int, int>> bfs_q;

    // We'll keep track of the current sea level and update accordingly
    int current_sea_level = 0;
    int remaining_area = H * W;

    // Vector to store how many cells get flooded at each year
    vector<int> flooded_per_year(Y + 2, 0); // 1-based index

    // Process all cells in increasing order of elevation
    while (!pq.empty())
    {
        auto [elevation, x, y] = pq.top();
        pq.pop();

        if (processed[x][y]) continue;

        // If this cell is on the edge or already connected to the sea, it's going to sink
        if ((x == 0 || y == 0 || x == H - 1 || y == W - 1) || !island[x][y])
        {
            if (!island[x][y])
            {
                island[x][y] = true; // Temporarily mark as land to allow BFS propagation
            }

            // Mark this cell as sinking at its own elevation
            flood_year[x][y] = elevation;
            island[x][y] = false;

            bfs_q.push({x, y});
            processed[x][y] = true;

            // Propagate flooding through connected low elevation cells
            while (!bfs_q.empty())
            {
                auto [cx, cy] = bfs_q.front();
                bfs_q.pop();

                for (int d = 0; d < 4; ++d)
                {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < H && ny < W && island[nx][ny] && A[nx][ny] <= elevation)
                    {
                        if (!processed[nx][ny])
                        {
                            flood_year[nx][ny] = A[nx][ny]; // Will flood at its own elevation
                            island[nx][ny] = false;
                            bfs_q.push({nx, ny});
                            processed[nx][ny] = true;
                        }
                    }
                }
            }
        }
        else
        {
            // This cell is not reachable yet, so we mark it as processed
            processed[x][y] = true;
        }
    }

    // Count how many cells flood at each year
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (flood_year[i][j] <= Y)
            {
                flooded_per_year[flood_year[i][j]]++;
            }
        }
    }

    // Calculate the area each year by subtracting cumulative flooded cells
    int ans = H * W;
    for (int i = 1; i <= Y; ++i)
    {
        ans -= flooded_per_year[i];
        cout << ans << "\n";
    }

    return 0;
}