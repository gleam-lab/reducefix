#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with all sections
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            pq.emplace(A[i][j], make_pair(i, j));
        }
    }

    const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> results(Y);

    for (int t = 1; t <= Y; ++t) {
        while (!pq.empty() && pq.top().first <= t) {
            auto [height, pos] = pq.top();
            pq.pop();

            if (visited[pos.first][pos.second]) continue;
            visited[pos.first][pos.second] = true;

            for (const auto& dir : directions) {
                int ni = pos.first + dir.first;
                int nj = pos.second + dir.second;
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    pq.emplace(A[ni][nj], make_pair(ni, nj));
                }
            }
        }
        results[t - 1] = H * W - count_if(begin(visited), end(visited), [](const auto& row) {
            return accumulate(begin(row), end(row), 0);
        });
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}