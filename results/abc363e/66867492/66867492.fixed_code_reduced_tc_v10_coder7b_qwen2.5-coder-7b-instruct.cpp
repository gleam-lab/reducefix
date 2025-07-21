#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Add boundary cells to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
        visited[i][0] = true;
        visited[i][W-1] = true;
    }
    for (int j = 1; j < W-1; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H-1][j], make_pair(H-1, j));
        visited[0][j] = true;
        visited[H-1][j] = true;
    }

    int ans = H * W;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();

            --ans;
            for (const auto& dir : directions) {
                int ny = pos.first + dir.first;
                int nx = pos.second + dir.second;
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx]) continue;

                visited[ny][nx] = true;
                pq.emplace(max(height, A[ny][nx]), make_pair(ny, nx));
            }
        }
        cout << ans << endl;
    }

    return 0;
}