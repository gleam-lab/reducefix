#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];
vector<int> Q[100005];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int y) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (!F[i][j] && A[i][j] <= y) {
                F[i][j] = true;
                q.push({i, j});
            }
    
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        --H;
        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !F[ni][nj] && A[ni][nj] <= y) {
                F[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];
    
    memset(F, 0, sizeof F);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = true;
                Q[A[i][j]].push({i, j});
            }
    
    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        cout << H * W << endl;
    }
    
    return 0;
}