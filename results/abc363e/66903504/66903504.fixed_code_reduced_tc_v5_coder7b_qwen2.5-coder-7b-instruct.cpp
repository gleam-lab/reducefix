#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int H,W,Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize visited array and queue
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);

    // Collect boundary cells and initialize queue
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q[A[i][j]].push({i, j});
            }
        }
    }

    // Process each year's rising sea level
    for(int y = 1; y <= Y; ++y) {
        while(!q[y].empty()) {
            auto [x, y] = q[y].front();
            q[y].pop();

            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    if(A[nx][ny] <= y) {
                        visited[nx][ny] = true;
                        q[y].push({nx, ny});
                    }
                }
            }
        }

        // Calculate the remaining area above sea level
        int remaining_area = 0;
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(!visited[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}