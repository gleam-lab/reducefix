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

    // This will track whether a cell is still above sea level
    vector<vector<bool>> above(Y + 2, vector<bool>(H * W, false));

    // Group cells by their elevation
    vector<vector<pair<int, int>>> elevCells(Y + 2);  // Only care up to Y
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (A[i][j] <= Y)
                elevCells[A[i][j]].emplace_back(i, j);
        }
    }

    // Initialize the grid: all cells start as above sea level
    vector<vector<bool>> gridAbove(H, vector<bool>(W, true));

    // BFS queue for each year
    vector<queue<pair<int, int>>> q(Y + 2);

    // First mark border cells and add them to corresponding queues
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] <= Y)
            {
                q[A[i][j]].push({i, j});
                gridAbove[i][j] = false;
            }
        }
    }

    // Total land area
    int remaining = H * W;

    // Process each year
    for (int year = 1; year <= Y; ++year)
    {
        // Store new submerged cells
        queue<pair<int, int>> tempQ = move(q[year]);

        while (!tempQ.empty())
        {
            auto [x, y] = tempQ.front();
            tempQ.pop();
            remaining--;

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < H && ny < W && gridAbove[nx][ny])
                {
                    // If neighbor's height <= current year, sink it
                    if (A[nx][ny] <= year)
                    {
                        gridAbove[nx][ny] = false;
                        tempQ.push({nx, ny});
                    }
                }
            }
        }

        // Save the current remaining area
        cout << remaining << "\n";
    }

    return 0;
}