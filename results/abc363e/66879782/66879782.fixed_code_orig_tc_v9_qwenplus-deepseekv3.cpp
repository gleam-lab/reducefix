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
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, pair<int, int>>>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({sink[i][j], {i, j}});
            }
        }
    }
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int current_h = current.first;
        int r = current.second.first;
        int c = current.second.second;
        
        if (current_h > sink[r][c]) continue;
        
        for (int k = 0; k < 4; k++) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            int new_sink = max(height[nr][nc], sink[r][c]);
            if (new_sink < sink[nr][nc]) {
                sink[nr][nc] = new_sink;
                pq.push({sink[nr][nc], {nr, nc}});
            }
        }
    }
    
    vector<int> cnt(y + 2, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sink[i][j] <= y) {
                cnt[sink[i][j]]++;
            }
        }
    }
    
    vector<int> pref(y + 1, 0);
    pref[0] = cnt[0];
    for (int i = 1; i <= y; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    
    for (int i = 1; i <= y; i++) {
        cout << h * w - pref[i] << '\n';
    }
    
    return 0;
}