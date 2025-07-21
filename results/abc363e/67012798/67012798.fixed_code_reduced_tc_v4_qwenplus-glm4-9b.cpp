#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> island(H, vector<bool>(W, true));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the queue with border cells and push their elevation to the queue
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1)) {
                q.push({A[i][j], i * W + j});
                island[i][j] = false;
            }
        }
    }

    // BFS to spread the sinking process
    while (!q.empty()) {
        int currentElevation = q.front().first;
        q.pop();
        int index = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = index / W + dx[d];
            int ny = index % W + dy[d];
            if (nx >= 0 && nx < H * W && ny >= 0 && ny < W && island[nx / W][ny] && A[nx / W][ny] <= currentElevation + 1) {
                q.push({A[nx / W][ny], nx});
                island[nx / W][ny] = false;
            }
        }
    }

    // Output the area of the island after each year
    for (int i = 1; i <= Y; i++) {
        int remainingArea = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (island[j][k]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}