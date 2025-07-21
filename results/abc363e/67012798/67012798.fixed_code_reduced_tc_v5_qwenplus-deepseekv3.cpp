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
    vector<vector<int>> earliest_sunk(H, vector<int>(W, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Initialize border cells
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                earliest_sunk[i][j] = A[i][j];
                pq.push({A[i][j], i, j});
            }
        }
    }

    int total = H * W;
    vector<int> ans(Y + 1, total);

    while (!pq.empty())
    {
        auto [time, x, y] = pq.top();
        pq.pop();

        if (sunk[x][y]) continue;
        sunk[x][y] = true;

        if (time <= Y)
        {
            ans[time]--;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (sunk[nx][ny]) continue;

            int new_time = max(time, A[nx][ny]);
            if (new_time < earliest_sunk[nx][ny])
            {
                earliest_sunk[nx][ny] = new_time;
                pq.push({new_time, nx, ny});
            }
        }
    }

    // Compute prefix sums of the answer
    for (int i = 1; i <= Y; i++)
    {
        ans[i] = min(ans[i], ans[i-1]);
    }

    for (int i = 1; i <= Y; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}