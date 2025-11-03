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

    // Use a priority queue to process cells in order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    
    // Add all border cells to the priority queue
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                pq.push({A[i][j], i, j});
                sunk[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> result(Y + 1, 0);

    // Process cells in increasing order of elevation
    while (!pq.empty())
    {
        auto [elevation, x, y] = pq.top();
        pq.pop();

        // This cell will sink at year = elevation
        if (elevation <= Y)
        {
            remaining--;
            result[elevation]++;
        }

        // Check neighbors
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny])
            {
                pq.push({A[nx][ny], nx, ny});
                sunk[nx][ny] = true;
            }
        }
    }

    // Handle cumulative sinking and output results
    int current_remaining = H * W;
    for (int i = 1; i <= Y; i++)
    {
        current_remaining -= result[i];
        cout << current_remaining << '\n';
    }

    return 0;
}