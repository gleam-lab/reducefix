#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> directions = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool canCapture(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1};
    }

    vector<vector<bool>> grid(N, vector<bool>(N, false));

    for (auto& p : pieces) {
        for (auto dir : directions) {
            int nx = p.first + dir.first;
            int ny = p.second + dir.second;
            if (canCapture(nx, ny)) {
                grid[nx][ny] = true;
            }
        }
    }

    long long count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!grid[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}