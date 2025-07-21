#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

bool isValid(int x, int y, int H, int h, int w) {
    return x >= 0 && x < h && y >= 0 && y < w && A[x][y] > H;
}

void floodFill(int r, int c, int H) {
    queue<Point> q;
    q.push({r, c});
    A[r][c] = H;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (isValid(nx, ny, H, h, w) && A[nx][ny] > H) {
                A[nx][ny] = H;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> A(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> years(y + 1, 0);
    int total = 0;
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            if (A[r][c] > 0) {
                int H = A[r][c];
                for (int i = 1; i <= min(H, y); ++i) {
                    years[i]++;
                }
                total++;
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        cout << total - years[i] << '\n';
    }

    return 0;
}