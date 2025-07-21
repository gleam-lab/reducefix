#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
const int INF = 1e9;

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> seen;

bool isBoundary(int x, int y) {
    return x == 0 || x == H - 1 || y == 0 || y == W - 1;
}

void bfs(int startHeight) {
    queue<P> q;
    seen.assign(H, vector<bool>(W, false));
    
    // Initialize BFS with the initial sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= startHeight && !seen[i][j]) {
                seen[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        P p = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = p.first + dy[k];
            int nj = p.second + dx[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !seen[ni][nj] && A[ni][nj] <= startHeight) {
                seen[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    A.assign(H, vector<int>(W));
    seen.assign(H, vector<bool>(W, false));

    rep(i, H) rep(j, W) cin >> A[i][j];

    // Initial area above sea level
    ll currentArea = H * W;
    rep(i, H) rep(j, W) if (!isBoundary(i, j) || A[i][j] > 0) currentArea--;

    rep(y = 1; y <= Y; ++y) {
        bfs(y);
        ll areaAfterYYears = H * W;
        rep(i, H) rep(j, W) if (!seen[i][j] && !isBoundary(i, j)) areaAfterYYears--;
        cout << areaAfterYYears << '\n';
    }

    return 0;
}