#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        submerged[i][0] = true;
        if (W > 1) {
            pq.emplace(A[i][W - 1], i, W - 1);
            submerged[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(A[0][j], 0, j);
        submerged[0][j] = true;
        if (H > 1) {
            pq.emplace(A[H - 1][j], H - 1, j);
            submerged[H - 1][j] = true;
        }
    }

    int remaining = H * W;
    vector<int> result(Y);
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            remaining--;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dy[d];
                int nj = j + dx[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                    submerged[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        result[year - 1] = remaining;
    }

    for (int y = 0; y < Y; ++y) {
        cout << result[y] << '\n';
    }

    return 0;
}