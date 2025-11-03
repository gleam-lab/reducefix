#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink_year(h, vector<int>(w, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int di[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> height[i][j];
            if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                sink_year[i][j] = height[i][j];
                pq.push({height[i][j], i, j});
            }
        }
    }
    
    while(!pq.empty()) {
        auto [year, r, c] = pq.top();
        pq.pop();
        
        if(sink_year[r][c] < year) continue;
        
        for(int i = 0; i < 4; i++) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            
            int new_sink_year = max(year, height[nr][nc]);
            if(new_sink_year < sink_year[nr][nc]) {
                sink_year[nr][nc] = new_sink_year;
                pq.push({new_sink_year, nr, nc});
            }
        }
    }
    
    vector<int> count(y + 1, 0);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(sink_year[i][j] <= y) {
                count[sink_year[i][j]]++;
            }
        }
    }
    
    int remaining = h * w;
    for(int i = 1; i <= y; i++) {
        remaining -= count[i];
        cout << remaining << '\n';
    }
}