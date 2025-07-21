#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));

void bfs(vector<vector<bool>>& visited, int start_i, int start_j, int sea_level) {
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= sea_level) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
    int ans = H * W;

    for (int year = 1; year <= Y; ++year) {
        // Mark sections that will sink in this year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] <= year) {
                    bfs(visited, i, j, year);
                }
            }
        }

        // Calculate remaining land area
        ans = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}