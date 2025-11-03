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
    vector<queue<pair<int, int>>> initial_queue(1e5 + 5);
    
    // Initialize: all border cells are adjacent to the sea
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                initial_queue[A[i][j]].push({i, j});
            }
        }
    }

    int remaining = H * W;

    // Process year by year
    for (int year = 1; year <= Y; year++)
    {
        queue<pair<int, int>> q;
        
        // Add all cells with elevation <= current sea level that are on the border
        while (!initial_queue[year].empty())
        {
            auto [x, y] = initial_queue[year].front();
            initial_queue[year].pop();
            
            if (!submerged[x][y])
            {
                submerged[x][y] = true;
                q.push({x, y});
                remaining--;
            }
        }
        
        // Flood fill from newly submerged cells
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || submerged[nx][ny])
                    continue;
                    
                // If adjacent cell's elevation <= current sea level, it also gets submerged
                if (A[nx][ny] <= year)
                {
                    submerged[nx][ny] = true;
                    q.push({nx, ny});
                    remaining--;
                }
            }
        }
        
        cout << remaining << '\n';
    }

    return 0;
}