#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Initialize border cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.emplace(A[i][j], i, j);
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y + 1, ans);
    result[0] = ans;

    for (int y = 1; y <= Y; y++) {
        while (!pq.empty() && get<0>(pq.top()) <= y) {
            auto [a, x, j] = pq.top();
            pq.pop();
            ans--;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = j + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
        result[y] = ans;
    }

    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}