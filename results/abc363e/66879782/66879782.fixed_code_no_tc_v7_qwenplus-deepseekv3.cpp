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
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    int di[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> height[i][j];
            if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    while(!pq.empty()) {
        auto [H, p] = pq.top();
        auto [r, c] = p;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if(max(H, height[nr][nc]) < sink[nr][nc]) {
                sink[nr][nc] = max(H, height[nr][nc]);
                pq.push({sink[nr][nc], {nr, nc}});
            }
        }
    }

    vector<int> count(1e5 + 2, 0);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(sink[i][j] <= 1e5) {
                count[sink[i][j]]++;
            }
        }
    }

    vector<int> prefix(y + 1, 0);
    prefix[0] = count[0];
    for(int i = 1; i <= y; i++) {
        prefix[i] = prefix[i-1] + count[i];
    }

    for(int i = 1; i <= y; i++) {
        cout << h * w - prefix[i] << '\n';
    }

    return 0;
}