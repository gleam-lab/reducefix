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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Push border cells into priority queue
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H-1 || j == 0 || j == W-1)
            {
                pq.push({A[i][j], {i, j}});
            }
        }
    }

    int ans = H * W;
    int current_sea_level = 0;

    for (int year = 1; year <= Y; year++)
    {
        current_sea_level = year;
        while (!pq.empty() && pq.top().first <= current_sea_level)
        {
            auto cell = pq.top();
            pq.pop();
            int elevation = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            if (sunk[x][y]) continue;

            sunk[x][y] = true;
            ans--;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (!sunk[nx][ny])
                {
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}