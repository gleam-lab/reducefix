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
    
    // Initially, add all border cells to the queue if they would be submerged at sea level 0
    // But since sea level starts at 0 and rises, we'll handle this incrementally
    int remaining = H * W;

    for (int year = 1; year <= Y; year++)
    {
        // Add new cells that become vulnerable at this sea level
        // Check all non-submerged cells with elevation <= year
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!submerged[i][j] && A[i][j] <= year)
                {
                    // Check if this cell is adjacent to any submerged cell or on the border
                    bool should_submerge = false;
                    
                    // Check if on border
                    if (i == 0 || i == H-1 || j == 0 || j == W-1)
                    {
                        should_submerge = true;
                    }
                    else
                    {
                        // Check if adjacent to submerged cell
                        for (int d = 0; d < 4; d++)
                        {
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            if (ni >= 0 && ni < H && nj >= 0 && nj < W && submerged[ni][nj])
                            {
                                should_submerge = true;
                                break;
                            }
                        }
                    }
                    
                    if (should_submerge)
                    {
                        submerged[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        
        // Propagate the submersion using BFS
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            
            // Check all four adjacent cells
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny] && A[nx][ny] <= year)
                {
                    submerged[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        // Count remaining cells (could also maintain a running count)
        int current_remaining = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!submerged[i][j])
                {
                    current_remaining++;
                }
            }
        }
        
        cout << current_remaining << endl;
    }

    return 0;
}