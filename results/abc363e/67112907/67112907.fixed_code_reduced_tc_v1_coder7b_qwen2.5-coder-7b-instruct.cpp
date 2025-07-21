#include <bits/stdc++.h>

using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to store sections to process
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    
    // Mark boundary sections and add to priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], make_pair(i, j));
            }
        }
    }

    int ans = H * W;
    set<pair<int, int>> visited;
    while (!pq.empty()) {
        auto [h, pos] = pq.top();
        pq.pop();

        if (visited.count(pos)) continue;
        visited.insert(pos);

        --ans;
        for (int k = 0; k < 4; k++) {
            int nx = pos.first + d[k][0], ny = pos.second + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited.count(make_pair(nx, ny))) {
                pq.emplace(A[nx][ny], make_pair(nx, ny));
            }
        }
    }

    vector<int> results(Y);
    results[0] = ans;

    for (int i = 1; i < Y; i++) {
        int h = i;
        while (!pq.empty() && pq.top().first <= h) {
            auto [_, pos] = pq.top();
            pq.pop();
            if (visited.count(pos)) continue;
            visited.insert(pos);
            --ans;
            for (int k = 0; k < 4; k++) {
                int nx = pos.first + d[k][0], ny = pos.second + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited.count(make_pair(nx, ny))) {
                    pq.emplace(A[nx][ny], make_pair(nx, ny));
                }
            }
        }
        results[i] = ans;
    }

    for (int i = 0; i < Y; i++) {
        cout << results[i] << '\n';
    }

    return 0;
}