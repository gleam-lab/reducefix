#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 1005;
const int D[] = {0, 1, 0, -1, 0};

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

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with border sections
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    for (int t = 0; t < Y; ++t) {
        int remaining_area = H * W;
        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            if (height <= t) {
                remaining_area--;
                for (int k = 0; k < 4; ++k) {
                    int nx = pos.first + D[k], ny = pos.second + D[k + 1];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= t) {
                        pq.emplace(A[nx][ny], make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            } else {
                break;
            }
        }
        cout << remaining_area << '\n';
    }

    return 0;
}