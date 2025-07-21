#include <bits/stdc++.h>
using namespace std;

#define H 1000
#define W 1000

int island[H][W];
int h, w, y;

void flood_fill(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    island[x][y] = 0;
    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        for (int dx : {-1, 0, 1}) {
            int nx = i + dx;
            for (int dy : {-1, 0, 1}) {
                int ny = j + dy;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && island[nx][ny] == 1) {
                    island[nx][ny] = 0;
                    Q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> island[i][j];
        }
    }
    
    int year;
    for (year = 1; year <= y; year++) {
        int remaining_area = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (island[i][j] == 1) {
                    flood_fill(i, j);
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }
    
    return 0;
}