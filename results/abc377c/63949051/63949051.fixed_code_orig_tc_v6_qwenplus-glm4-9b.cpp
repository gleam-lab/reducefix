#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 1000000000;

bool can_capture(int a, int b, int dx, int dy) {
    return a + dx >= 1 && a + dx <= MAX_N && b + dy >= 1 && b + dy <= MAX_N;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_map<int, unordered_map<int, bool>> captured;
    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

        for (int i = 0; i < 8; ++i) {
            if (can_capture(x, y, dx[i], dy[i])) {
                captured[x][y] = true;
            }
        }
    }

    int safe_squares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!captured[i][j]) {
                ++safe_squares;
            }
        }
    }

    cout << safe_squares << endl;

    return 0;
}