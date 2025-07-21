#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int MAXN = 1005;

int h, w, y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

int bfs(int sea_level) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A[i][j] > sea_level) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    int count = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        count++;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && A[nx][ny] > sea_level) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= y; ++i) {
        cout << bfs(i) << '\n';
    }
    return 0;
}