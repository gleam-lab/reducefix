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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    queue<pair<int, int>> q;
    
    // Initialize: all boundary cells with elevation <= 1 will sink in year 1
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] <= 1)
            {
                sunk[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int remaining = H * W;
    
    // Process year 1 separately since we've initialized boundary cells <= 1
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 && ny >= 0 && nx < H && ny < W && !sunk[nx][ny] && A[nx][ny] <= 1)
            {
                sunk[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    // Count remaining after year 1
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (sunk[i][j])
                remaining--;
        }
    }
    
    cout << remaining << endl;
    
    // Process years 2 to Y
    for (int year = 2; year <= Y; year++)
    {
        // Find all cells that have elevation exactly equal to current year
        // and are adjacent to already sunk cells
        queue<pair<int, int>> new_sunk;
        
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!sunk[i][j] && A[i][j] <= year)
                {
                    // Check if this cell is adjacent to any sunk cell
                    bool adjacent_to_sunk = false;
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && nj >= 0 && ni < H && nj < W && sunk[ni][nj])
                        {
                            adjacent_to_sunk = true;
                            break;
                        }
                    }
                    
                    if (adjacent_to_sunk)
                    {
                        sunk[i][j] = true;
                        new_sunk.push({i, j});
                    }
                }
            }
        }
        
        // Use BFS to propagate the sinking effect
        while (!new_sunk.empty())
        {
            auto [x, y] = new_sunk.front();
            new_sunk.pop();
            
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && ny >= 0 && nx < H && ny < W && !sunk[nx][ny] && A[nx][ny] <= year)
                {
                    sunk[nx][ny] = true;
                    new_sunk.push({nx, ny});
                }
            }
        }
        
        // Recalculate remaining area
        remaining = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!sunk[i][j])
                    remaining++;
            }
        }
        
        cout << remaining << endl;
    }

    return 0;
}