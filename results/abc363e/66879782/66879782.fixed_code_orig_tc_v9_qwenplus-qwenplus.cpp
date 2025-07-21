#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    int height[h][w];
    int sink[h][w];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            sink[i][j] = INT_MAX;
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    bool visited[h][w];
    memset(visited, false, sizeof(visited));

    while (!pq.empty()) {
        auto [H, p] = pq.top();
        auto [r, c] = p;
        pq.pop();
        if (visited[r][c]) continue;
        visited[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (height[nr][nc] <= H && sink[nr][nc] > H) {
                sink[nr][nc] = H;
                pq.push({H, {nr, nc}});
            }
        }
    }

    vector<int> count(y + 2, 0); // We use y+2 to avoid index issues in prefix sum
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sink[i][j] <= y) {
                count[sink[i][j]]++;
            }
        }
    }

    // Compute prefix sum
    vector<int> prefix(y + 2, 0);
    for (int i = 1; i <= y; i++) {
        prefix[i] = prefix[i - 1] + count[i];
        cout << h * w - prefix[i] << '\n';
    }

    return 0;
}