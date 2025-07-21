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

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1, 0);

    for (int i = 1; i <= Y; i++)
    {
        while (!pq.empty() && pq.top().first <= i)
        {
            auto current = pq.top();
            pq.pop();
            int x = current.second.first;
            int y = current.second.second;

            if (A[x][y] > i)
            {
                continue;
            }

            ans--;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                {
                    continue;
                }

                if (!sunk[nx][ny])
                {
                    sunk[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }

        res[i] = ans;
    }

    for (int i = 1; i <= Y; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}