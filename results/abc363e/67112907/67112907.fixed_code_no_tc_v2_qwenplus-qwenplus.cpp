#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    // Priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        if (!sunk[i][0]) {
            pq.emplace(A[i][0], i, 0);
            sunk[i][0] = true;
        }
        if (!sunk[i][W-1]) {
            pq.emplace(A[i][W-1], i, W-1);
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!sunk[0][j]) {
            pq.emplace(A[0][j], 0, j);
            sunk[0][j] = true;
        }
        if (!sunk[H-1][j]) {
            pq.emplace(A[H-1][j], H-1, j);
            sunk[H-1][j] = true;
        }
    }

    // Sort all queries (year -> index)
    vector<pair<int, int>> queries(Y);
    for (int i = 0; i < Y; ++i) {
        queries[i] = {i + 1, i};
    }

    // We'll store answers by year
    vector<int> answer(Y);
    int remaining = H * W;

    // Process queries in increasing order of year
    sort(queries.begin(), queries.end());

    int curr_year = 0;
    for (const auto& [year, idx] : queries) {
        // Advance sea level to this year
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [h, x, y] = pq.top();
            pq.pop();
            --remaining;

            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
        answer[idx] = remaining;
    }

    for (int i = 0; i < Y; ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}