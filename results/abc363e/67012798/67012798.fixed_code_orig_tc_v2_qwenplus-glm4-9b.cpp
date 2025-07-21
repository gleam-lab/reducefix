#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 5;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int H, W, Y;
vector<vector<int>> A(H, vector<int>(W));
vector<vector<bool>> visited(H, vector<bool>(W, false));
int waterLevel = 1; // Start with sea level 1

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] <= waterLevel)
            {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || visited[nx][ny] || A[nx][ny] > waterLevel)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> H >> W >> Y;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    ans = H * W; // Start with the total area
    for (int year = 1; year <= Y; year++)
    {
        bfs(); // Perform BFS to sink the land
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (!visited[i][j]) // If the cell hasn't been visited by BFS, it's above the sea level
                    ans--; // Decrease since this cell is not sinking
        waterLevel++; // Increase sea level by 1
        cout << ans << "\n";
    }

    return 0;
}