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

    vector<vector<bool>> island(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> q(Y + 1); // Only need up to Y years

    // Initialize: add all border cells with elevation <= Y to their respective year queues
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
            {
                if (A[i][j] <= Y)
                {
                    q[A[i][j]].push({i, j});
                    island[i][j] = false;
                }
            }
        }
    }

    int ans = H * W;

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; year++)
    {
        // Use a BFS-like approach for this year's sea level rise
        queue<pair<int, int>> current_q;
        
        // Add all cells that have elevation exactly 'year'
        while (!q[year].empty())
        {
            auto [x, y] = q[year].front();
            q[year].pop();
            current_q.push({x, y});
        }

        // Process all cells that sink at this year
        while (!current_q.empty())
        {
            auto [x, y] = current_q.front();
            current_q.pop();
            ans--;

            // Check neighbors
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;

                if (island[nx][ny] && A[nx][ny] <= year)
                {
                    island[nx][ny] = false;
                    current_q.push({nx, ny});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}