#include<bits/stdc++.h>
using namespace std;

int H, W, Y;
int A[1001][1001];
bool visited[1001][1001];

// Directions for the flood fill (8 possible directions)
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

// Function to perform flood fill from a given cell
void floodFill(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= A[x][y] + Y) {
            floodFill(nx, ny);
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    int remainingArea = H * W;
    for (int y = 0; y < Y; y++) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!visited[i][j] && (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] == A[i][j - 1] || A[i][j] == A[i - 1][j])) {
                    floodFill(i, j);
                    remainingArea -= floodFill_area(i, j);
                }
            }
        }
        cout << remainingArea << endl;
    }
    return 0;
}

int floodFill_area(int x, int y) {
    int area = 1;
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= A[x][y] + Y) {
            area += floodFill_area(nx, ny);
        }
    }
    return area;
}