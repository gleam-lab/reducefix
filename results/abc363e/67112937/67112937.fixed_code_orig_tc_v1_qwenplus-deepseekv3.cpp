#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize with all border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y);
    
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [h, x, y] = pq.top();
            pq.pop();
            --ans;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
        res[year - 1] = ans;
    }

    for (int y = 0; y < Y; ++y) {
        cout << res[y] << '\n';
    }

    return 0;
}