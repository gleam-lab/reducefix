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
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                pq.push({A[i][j], i, j});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    int current_sunk = 0;
    vector<int> res(Y + 1, 0);

    for (int year = 1; year <= Y; year++)
    {
        queue<pair<int, int>> q;
        while (!pq.empty() && get<0>(pq.top()) <= year)
        {
            auto [elev, x, y] = pq.top();
            pq.pop();
            q.push({x, y});
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            current_sunk++;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || sunk[nx][ny])
                {
                    continue;
                }
                if (A[nx][ny] <= year)
                {
                    sunk[nx][ny] = true;
                    q.push({nx, ny});
                }
                else
                {
                    pq.push({A[nx][ny], nx, ny});
                    sunk[nx][ny] = true;
                }
            }
        }
        res[year] = H * W - current_sunk;
    }

    for (int i = 1; i <= Y; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}