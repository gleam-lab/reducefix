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
    vector<vector<pair<int, int>>> q_sinks(1e5 + 5);

    // Process border cells first
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                q_sinks[A[i][j]].emplace_back(i, j);
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y + 1);

    for (int y = 1; y <= 1e5; y++)
    {
        for (auto [x, j] : q_sinks[y])
        {
            ans--;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = j + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && island[nx][ny] && A[nx][ny] <= y)
                {
                    island[nx][ny] = false;
                    q_sinks[A[nx][ny]].emplace_back(nx, ny);
                }
            }
        }

        if (y <= Y)
        {
            result[y] = ans;
        }
        else
        {
            break;
        }
    }

    for (int y = 1; y <= Y; y++)
    {
        cout << result[y] << '\n';
    }

    return 0;
}