#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool isValid(Point p, int N) {
    return p.x >= 0 && p.x < N && p.y >= 0 && p.y < N;
}

bool canCapture(Point p1, Point p2) {
    int dx = abs(p1.x - p2.x), dy = abs(p1.y - p2.y);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int countValidSquares(int N, int M, vector<Point>& pieces) {
    vector<vector<bool>> board(N, vector<bool>(N, false));
    for (auto& p : pieces) {
        board[p.x][p.y] = true;
    }

    int validSquares = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!board[i][j]) {
                bool canBeCaptured = false;
                for (auto& p : pieces) {
                    Point candidate{i, j};
                    if (canCapture(candidate, p)) {
                        canBeCaptured = true;
                        break;
                    }
                }
                if (!canBeCaptured) {
                    ++validSquares;
                }
            }
        }
    }
    return validSquares;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<Point> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
        --pieces[i].x; // Adjusting 1-based index to 0-based index
        --pieces[i].y; // Adjusting 1-based index to 0-based index
    }

    cout << countValidSquares(N, M, pieces) << endl;

    return 0;
}