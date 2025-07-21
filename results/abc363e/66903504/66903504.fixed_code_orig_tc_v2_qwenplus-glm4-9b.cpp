#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> Q(Y + 1);
    int remaining_area = 0;

    // Initial sinking
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int count = 0;
            if (i > 0 && A[i][j] > A[i - 1][j]) count++;
            if (i < H - 1 && A[i][j] > A[i + 1][j]) count++;
            if (j > 0 && A[i][j] > A[i][j - 1]) count++;
            if (j < W - 1 && A[i][j] > A[i][j + 1]) count++;
            if (count == 4) {
                remaining_area++;
                visited[i][j] = true;
                Q[1].push({i, j});
            }
        }
    }

    // Process sinking each year
    for (int y = 1; y <= Y; ++y) {
        queue<pair<int, int>> temp;
        while (!Q[y].empty()) {
            auto [x, y] = Q[y].front();
            Q[y].pop();
            remaining_area--;

            if (x > 0 && !visited[x - 1][y] && A[x - 1][y] <= A[x][y]) {
                visited[x - 1][y] = true;
                temp.push({x - 1, y});
                remaining_area++;
            }
            if (x < H - 1 && !visited[x + 1][y] && A[x + 1][y] <= A[x][y]) {
                visited[x + 1][y] = true;
                temp.push({x + 1, y});
                remaining_area++;
            }
            if (y > 0 && !visited[x][y - 1] && A[x][y - 1] <= A[x][y]) {
                visited[x][y - 1] = true;
                temp.push({x, y - 1});
                remaining_area++;
            }
            if (y < W - 1 && !visited[x][y + 1] && A[x][y + 1] <= A[x][y]) {
                visited[x][y + 1] = true;
                temp.push({x, y + 1});
                remaining_area++;
            }
        }
        Q[y + 1] = temp;
        cout << remaining_area << endl;
    }

    return 0;
}