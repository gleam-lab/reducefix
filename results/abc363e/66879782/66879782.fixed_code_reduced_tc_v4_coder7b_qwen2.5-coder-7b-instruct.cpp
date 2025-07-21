#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> sink(h, vector<bool>(w, false));

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if(height[i][j] > y) sink[i][j] = true;
        }
    }

    vector<int> dir = {-1, 0, 1, 0, -1};
    int ans = h * w;

    for(int l = 1; l <= y; ++l) {
        int sz = ans;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(!sink[i][j] && height[i][j] <= l) {
                    queue<pi> q;
                    q.push({height[i][j], {i, j}});
                    sink[i][j] = true;

                    while(!q.empty()) {
                        auto [hl, p] = q.front(); q.pop();
                        int x = p.first, y = p.second;
                        for(int k = 0; k < 4; ++k) {
                            int nx = x + dir[k], ny = y + dir[k + 1];
                            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !sink[nx][ny] && height[nx][ny] <= l) {
                                sink[nx][ny] = true;
                                q.push({height[nx][ny], {nx, ny}});
                            }
                        }
                    }
                }
            }
        }
        ans -= (sz - ans);
        cout << ans << '\n';
    }

    return 0;
}