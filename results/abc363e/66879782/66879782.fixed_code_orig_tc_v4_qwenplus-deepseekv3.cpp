#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink_time(h, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink_time[i][j] = height[i][j];
                pq.push({sink_time[i][j], {i, j}});
            }
        }
    }
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int current_time = current.first;
        int i = current.second.first;
        int j = current.second.second;
        
        if (current_time > sink_time[i][j]) {
            continue;
        }
        
        for (int d = 0; d < 4; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                int new_time = max(current_time, height[ni][nj]);
                if (new_time < sink_time[ni][nj]) {
                    sink_time[ni][nj] = new_time;
                    pq.push({new_time, {ni, nj}});
                }
            }
        }
    }
    
    vector<int> prefix(y + 2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_time[i][j] <= y) {
                prefix[sink_time[i][j]]++;
            }
        }
    }
    
    for (int i = 1; i <= y; ++i) {
        prefix[i] += prefix[i - 1];
    }
    
    for (int i = 1; i <= y; ++i) {
        cout << h * w - prefix[i] << '\n';
    }
    
    return 0;
}