#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 1001

int H, W, Y;
int A[MAXN][MAXN];
int remainingArea[MAXN][MAXN];
int initSeaLevel;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the remaining area and the flood level
    memset(remainingArea, -1, sizeof(remainingArea)); // -1 means submerged
    initSeaLevel = 0;

    // Find the highest elevation land
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] > initSeaLevel) {
                q.push({i, j});
                remainingArea[i][j] = 1;
            }
        }
    }

    // Perform BFS to find all land at or above the initial sea level
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isValid(nx, ny) && A[nx][ny] >= initSeaLevel && remainingArea[nx][ny] == -1) {
                remainingArea[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    // Simulate the rising sea level for Y years
    int currentSeaLevel = initSeaLevel;
    int currentRemainingArea = 0;
    for (int year = 0; year < Y; year++) {
        currentSeaLevel++;
        int newRemainingArea = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (A[i][j] > currentSeaLevel && remainingArea[i][j] == 1) {
                    // Land is submerged
                    remainingArea[i][j] = 0;
                } else if (remainingArea[i][j] == 1) {
                    // Land is still above sea level
                    newRemainingArea++;
                }
            }
        }
        currentRemainingArea = newRemainingArea;
        cout << currentRemainingArea << endl;
    }

    return 0;
}