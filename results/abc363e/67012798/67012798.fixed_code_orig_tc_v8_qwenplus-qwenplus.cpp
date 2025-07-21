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

    // Event-based processing using a queue per year not feasible due to memory
    // Instead, we use a priority queue (min-heap) based on elevation
    using Cell = pair<int, pair<int, int>>;
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    // Mark and enqueue boundary cells
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                pq.push({A[i][j], {i, j}});
                island[i][j] = false;
            }
        }
    }

    // Total area of the island
    long long ans = 1LL * H * W;

    // Process each year
    vector<long long> result(Y + 2, 0);
    for (int y = 1; y <= Y; ++y)
    {
        result[y] = ans;
    }

    // BFS with priority queue
    while (!pq.empty())
    {
        auto [elev, pos] = pq.top();
        pq.pop();
        auto [x, y] = pos;

        if (elev > Y)
        {
            continue;
        }

        if (result[elev] > 0)
        {
            result[elev]--;
        }
        else
        {
            ans--;
        }

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < H && ny < W && island[nx][ny])
            {
                if (A[nx][ny] <= elev)
                {
                    island[nx][ny] = false;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
    }

    // Final pass to handle dependencies between years
    for (int y = 1; y <= Y; ++y)
    {
        if (result[y] == 0)
        {
            result[y] = ans;
        }
        cout << result[y] << "\n";
    }

    return 0;
}