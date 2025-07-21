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
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> height[i][j];

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> queue;
    
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(i == 0 || i == h-1 || j == 0 || j == w-1)
                queue.push_back({i, j});
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while(!queue.empty()) {
        int x = queue.front()[0], y = queue.front()[1];
        queue.erase(queue.begin());
        
        if(seen[x][y]) continue;
        seen[x][y] = true;

        for(int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !seen[nx][ny] && height[nx][ny] <= height[x][y])
                queue.push_back({nx, ny});
        }
    }

    vector<int> result(y+1, 0);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(!seen[i][j]) {
                ++result[height[i][j]];
            }
        }
    }

    for(int i = 1; i <= y; ++i) {
        result[i] += result[i-1];
        cout << h * w - result[i] << "\n";
    }

    return 0;
}