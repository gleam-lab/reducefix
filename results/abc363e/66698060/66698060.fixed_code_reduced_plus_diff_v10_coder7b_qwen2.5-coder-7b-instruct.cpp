#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) cin >> a[i][j];

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    vector<vector<int>> res(y + 1, vector<int>(h * w));

    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) {
        if(a[i][j] <= 0) continue;
        if(seen[i][j]) continue;
        seen[i][j] = true;
        q.push({i, j});
        int cnt = 1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] > 0 && !seen[nx][ny]) {
                    seen[nx][ny] = true;
                    q.push({nx, ny});
                    ++cnt;
                }
            }
        }
        res[cnt].push_back(-a[i][j]);
    }

    for(int i = 1; i <= y; ++i) sort(res[i].begin(), res[i].end());

    for(int i = 1; i <= y; ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            res[i][j] += res[i - 1][j];
        }
    }

    for(int i = 1; i <= y; ++i) {
        int ans = h * w;
        for(int j = 0; j < res[i].size(); ++j) {
            ans -= res[i][j];
        }
        cout << ans << '\n';
    }

    return 0;
}