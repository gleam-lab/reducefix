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
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int di[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> height[i][j];
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], i, j});
            }
        }
    }

    while (!pq.empty()) {
        auto [elev, r, c] = pq.top();
        pq.pop();
        if (elev != sink[r][c]) continue; // Skip outdated entries

        for (int i = 0; i < 4; i++) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            
            int new_elev = max(height[nr][nc], elev); // Water can only flow in if the elevation is <= current water level
            if (new_elev < sink[nr][nc]) {
                sink[nr][nc] = new_elev;
                pq.push({new_elev, nr, nc});
            }
        }
    }

    vector<int> area(y + 1, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sink[i][j] <= y) {
                area[sink[i][j]]++;
            }
        }
    }

    int remaining = h * w;
    for (int year = 1; year <= y; year++) {
        remaining -= area[year];
        cout << remaining << '\n';
    }

    return 0;
}