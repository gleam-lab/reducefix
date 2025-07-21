#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1000000000; // 10^9
const int MAX_M = 200000; // 2 * 10^5

struct Point {
    int x, y;
};

struct Direction {
    int dx, dy;
};

const Direction directions[8] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Point> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
        --pieces[i].x; // Adjust for 0-based index
        --pieces[i].y; // Adjust for 0-based index
    }

    vector<vector<vector<bool>>> cap(N, vector<vector<bool>>(N, vector<bool>(8, false)));

    // Mark the capture boundaries for each piece
    for (const auto& p : pieces) {
        for (int i = 0; i < 8; ++i) {
            int nx = p.x;
            int ny = p.y;
            while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                cap[nx][ny][i] = true;
                nx += directions[i].dx;
                ny += directions[i].dy;
            }
        }
    }

    // Count the number of safe squares
    long long safe_squares = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool captured = false;
            for (int k = 0; k < 8; ++k) {
                if (cap[i][j][k]) {
                    captured = true;
                    break;
                }
            }
            if (!captured) {
                ++safe_squares;
            }
        }
    }

    cout << safe_squares << endl;

    return 0;
}