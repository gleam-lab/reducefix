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
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1);

    for (int y = 1; y <= Y; y++) {
        while (!pq.empty() && get<0>(pq.top()) <= y) {
            auto [a, i, j] = pq.top();
            pq.pop();
            ans--;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    sunk[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        res[y] = ans;
    }

    for (int y = 1; y <= Y; y++) {
        cout << res[y] << '\n';
    }

    return 0;
}