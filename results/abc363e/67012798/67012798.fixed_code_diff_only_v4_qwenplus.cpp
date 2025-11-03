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
    vector<vector<bool>> in_queue(H, vector<bool>(W, false));
    
    queue<pair<int, int>> q;
    
    // Initialize: all border cells are adjacent to the sea
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                q.push({i, j});
                in_queue[i][j] = true;
            }
        }
    }

    int ans = H * W;

    for (int year = 1; year <= Y; year++)
    {
        // Process all cells that will submerge at current sea level
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            
            // If already submerged, skip
            if (submerged[x][y]) continue;
            
            // Check if this cell submerges at current sea level
            if (A[x][y] <= year)
            {
                submerged[x][y] = true;
                ans--;
                
                // Add adjacent cells for potential future submersion
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !in_queue[nx][ny])
                    {
                        q.push({nx, ny});
                        in_queue[nx][ny] = true;
                    }
                }
            }
        }
        
        cout << ans << '\n';
        
        // Reset the queue for next year with newly exposed border cells
        // But we need to preserve cells that weren't processed yet
        // Instead, let's restructure: we'll maintain a priority-based approach
        
        // Actually, let's change strategy: use event-based processing
    }
    
    // The above approach has issues. Let's rewrite completely.
    return 0;
}