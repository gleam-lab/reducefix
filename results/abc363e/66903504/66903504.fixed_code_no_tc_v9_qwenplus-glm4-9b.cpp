#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define pb push_back

using ll = long long;
const int INF = 1000000000;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Initialize the visited array and queue for the BFS
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] == 0) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    vector<vector<bool>> sink(H, vector<bool>(W, false));

    // Perform BFS to determine the initial set of sinking cells
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // Satellite view to determine the maximum distance from the shore
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                        sink[nx][ny] = max(sink[nx][ny], visited[i][j] + 1);
                    }
                }
            }
        }
    }

    // Calculate the remaining area after Y years
    ll remaining_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] > Y && A[i][j] > sink[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the result for each year
    for (int y = 1; y <= Y; y++) {
        cout << remaining_area << endl;
    }

    return 0;
}