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

    // Create a map of queues for each possible year
    vector<queue<pair<int, int>>> q(Y + 2); // Y can be up to 1e5

    // Mark border cells for initial flooding
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                int level = A[i][j];
                if (level <= Y)
                {
                    q[level].push({i, j});
                    island[i][j] = false;
                }
            }
        }
    }

    int ans = H * W;

    // Process each year
    for (int year = 1; year <= Y; ++year)
    {
        queue<pair<int, int>> temp_q = move(q[year]);
        while (!temp_q.empty())
        {
            ans--;
            auto [x, y] = temp_q.front();
            temp_q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && island[nx][ny])
                {
                    int next_level = A[nx][ny];
                    if (next_level <= Y && next_level >= year)
                    {
                        q[next_level].push({nx, ny});
                        island[nx][ny] = false;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}