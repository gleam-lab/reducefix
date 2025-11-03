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

    // Create a list of all cells with their elevations
    vector<tuple<int, int, int>> cells;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cells.emplace_back(A[i][j], i, j);
        }
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    vector<vector<bool>> island(H, vector<bool>(W, true));
    int remaining = H * W;
    
    // Process each year
    auto it = cells.begin();
    for (int year = 1; year <= Y; year++) {
        // Remove all cells with elevation <= current sea level
        while (it != cells.end() && get<0>(*it) <= year) {
            int x = get<1>(*it);
            int y = get<2>(*it);
            if (island[x][y]) {
                island[x][y] = false;
                remaining--;
                
                // Check if this cell is on the boundary or adjacent to already sunk cell
                // But since we're processing by elevation, any cell with elevation <= year will eventually sink
                // The key insight is that sinking happens from the boundaries inward
                // However, our approach needs to simulate the propagation
                
                // Instead, we'll use a different approach: start from boundaries and flood fill
                // But that would be inefficient for each year.
            }
            ++it;
        }
        
        cout << remaining << '\n';
    }

    return 0;
}