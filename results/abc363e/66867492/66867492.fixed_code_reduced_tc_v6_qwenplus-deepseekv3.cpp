#include <bits/stdc++.h>
using namespace std;

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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Push boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                sunk[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> result(Y + 1, remaining);
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [height, i, j] = pq.top();
            pq.pop();
            remaining--;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    sunk[ni][nj] = true;
                    pq.emplace(A[ni][nj], ni, nj);
                }
            }
        }
        result[year] = remaining;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}