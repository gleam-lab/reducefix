#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void processYear(int year, vector<vector<int>>& A, vector<vector<bool>>& visited, int& remainingArea) {
    set<pair<int, int>> sinking;
    queue<pair<int, int>> q;

    // Find all sections that will sink this year
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (!visited[i][j] && A[i][j] + year <= 0) {
                visited[i][j] = true;
                q.push({i, j});
                sinking.insert({i, j});
            }
        }
    }

    // Perform the flood fill to propagate the sinking
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= A.size() || ny < 0 || ny >= A[0].size()) continue;
                if (visited[nx][ny] || A[nx][ny] + year > 0) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
                sinking.insert({nx, ny});
            }
        }
    }

    // Update the remaining area
    remainingArea -= sinking.size();
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int remainingArea = H * W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int year = 0; year < Y; ++year) {
        processYear(year, A, visited, remainingArea);
        cout << remainingArea << endl;
    }

    return 0;
}