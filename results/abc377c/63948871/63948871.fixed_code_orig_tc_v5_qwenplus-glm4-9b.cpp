#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[9] = {-2, -2, -1, -1, 1, 1, 2, 2, 0};
const int dy[9] = {-1, 1, -2, 2, -2, 2, -1, 1, 0};

bool can_place(vector<vector<bool>>& grid, int x, int y, const vector<pair<int, int>>& pieces) {
    for (auto& p : pieces) {
        int px = p.first - 1;
        int py = p.second - 1;
        for (int i = 1; i <= 8; ++i) {
            if (grid[px + dx[i]][py + dy[i]] || grid[px + dx[i + 1]][py + dy[i + 1]]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<vector<bool>> grid(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first - 1;
        int y = pieces[i].second - 1;
        grid[x][y] = true;
        for (int j = 1; j <= 8; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                grid[nx][ny] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!grid[i][j]) {
                if (can_place(grid, i + 1, j + 1, pieces)) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}