#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y + 1, ans); // result[y] is the answer for sea level y

    int current_sea_level = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        int elevation = top.first;
        int i = top.second.first;
        int j = top.second.second;
        pq.pop();

        if (elevation > current_sea_level) {
            for (int y = current_sea_level + 1; y <= min(elevation, Y); ++y) {
                result[y] = ans;
            }
            current_sea_level = min(elevation, Y);
        }

        if (current_sea_level >= elevation) {
            ans--;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    sunk[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
    }

    // Fill remaining sea levels if any
    for (int y = current_sea_level + 1; y <= Y; ++y) {
        result[y] = ans;
    }

    for (int y = 1; y <= Y; ++y) {
        cout << result[y] << '\n';
    }

    return 0;
}