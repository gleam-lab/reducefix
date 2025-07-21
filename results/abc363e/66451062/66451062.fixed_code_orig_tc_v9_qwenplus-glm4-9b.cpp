#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;

void addQueue(priority_queue<pair<int, pair<int, int>>> &q, int x, int y, int level) {
    q.push({level - A[x][y], {x, y}});
    A[x][y] = level;
}

signed main() {
    close;
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> A(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    bool visited[h][w] = {{false}};
    priority_queue<pair<int, pair<int, int>>> q;
    // Start with cells on the boundary that are at sea level
    for(int i = 0; i < h; i++) {
        addQueue(q, i, 0, A[i][0]);
        addQueue(q, i, w - 1, A[i][w - 1]);
        visited[i][0] = visited[i][w - 1] = true;
    }
    for(int i = 1; i < w - 1; i++) {
        addQueue(q, 0, i, A[0][i]);
        addQueue(q, h - 1, i, A[h - 1][i]);
        visited[0][i] = visited[h - 1][i] = true;
    }

    int remaining_area = h * w;
    while(y--) {
        pair<int, pair<int, int>> curr = q.top(); q.pop();
        int x = curr.second.first, y = curr.second.second, level = curr.first;

        remaining_area -= (level == A[x][y] ? 0 : 1); // If this cell was not previously visited, it has just flooded

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && A[nx][ny] <= level) {
                visited[nx][ny] = true;
                addQueue(q, nx, ny, level + 1);
            }
        }
    }
    cout << remaining_area << endl;
    return 0;
}