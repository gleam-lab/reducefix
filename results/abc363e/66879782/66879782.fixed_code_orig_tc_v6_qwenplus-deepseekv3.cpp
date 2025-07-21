#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink_time(h, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink_time[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int current_time = current.first;
        int r = current.second.first;
        int c = current.second.second;
        if (current_time > sink_time[r][c]) continue;
        for (int k = 0; k < 4; ++k) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            int new_time = max(current_time, height[nr][nc]);
            if (new_time < sink_time[nr][nc]) {
                sink_time[nr][nc] = new_time;
                pq.push({new_time, {nr, nc}});
            }
        }
    }

    vector<int> freq(y + 2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_time[i][j] <= y) {
                freq[sink_time[i][j]]++;
            }
        }
    }

    int total_sunk = 0;
    for (int i = 1; i <= y; ++i) {
        total_sunk += freq[i];
        cout << h * w - total_sunk << '\n';
    }

    return 0;
}