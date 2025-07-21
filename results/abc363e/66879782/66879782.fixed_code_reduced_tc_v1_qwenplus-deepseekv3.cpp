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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int H = current.first;
        int r = current.second.first;
        int c = current.second.second;
        
        for (int k = 0; k < 4; ++k) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (sink[nr][nc] > H) {
                sink[nr][nc] = max(height[nr][nc], H);
                pq.push({sink[nr][nc], {nr, nc}});
            }
        }
    }
    
    vector<int> cnt(y + 2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] <= y) {
                cnt[sink[i][j]]++;
            }
        }
    }
    
    vector<int> prefix(y + 1, 0);
    prefix[0] = cnt[0];
    for (int i = 1; i <= y; ++i) {
        prefix[i] = prefix[i - 1] + cnt[i];
    }
    
    for (int i = 1; i <= y; ++i) {
        cout << h * w - prefix[i] << '\n';
    }
    
    return 0;
}