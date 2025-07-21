#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> used;
vector<vector<int>> cells;
priority_queue<pair<int, pair<int, int>>> pq;

void addCell(int x, int y) {
    cells.push_back({x, y, A[x][y]});
    pq.push({-A[x][y], {x, y}});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    rep(i, H) {
        A.push_back(vector<int>(W));
        rep(j, W) {
            cin >> A[i][j];
        }
    }
    cells.resize(H * W);
    used.resize(H, vector<bool>(W, false));
    rep(i, H) {
        rep(j, W) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                addCell(i, j);
                used[i][j] = true;
            }
        }
    }
    rep(i, Y) {
        while (!pq.empty() && pq.top().first < 0) {
            auto [x, y] = pq.top().second;
            pq.pop();
            rep(k, 4) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny] && A[nx][ny] > i + 1) {
                    addCell(nx, ny);
                    used[nx][ny] = true;
                }
            }
        }
        cout << (H * W - (int)pq.size()) << '\n';
    }
    return 0;
}