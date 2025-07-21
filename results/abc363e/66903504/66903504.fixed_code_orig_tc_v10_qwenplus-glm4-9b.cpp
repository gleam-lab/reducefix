#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    
    // Read the elevation matrix
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Initialize the queue and the answer
    queue<pair<int, int>> Q;
    vector<vector<bool>> F(H, vector<bool>(W, false)); // true means above sea level
    int ans = 0;

    // Initialize the queue with cells that are initially underwater
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] <= 0) {
                F[i][j] = false;
                ans++;
            }
        }
    }

    // Perform the simulation
    for (int y = 1; y <= Y; ++y) {
        int currentYear = y;
        while (!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            ans--;

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                        if (A[nx][ny] > currentYear && F[nx][ny]) {
                            F[nx][ny] = false;
                            Q.push({nx, ny});
                            ans--;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}