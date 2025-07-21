#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXY = 100005;
int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];
vector<int> adj[MAXY];

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
        for (auto [di, dj] : {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !F[ni][nj] && A[ni][nj] <= y) {
                F[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            adj[A[i][j]].push_back(i * W + j);
        }
    
    memset(F, 0, sizeof(F));
    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        int cnt = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!F[i][j])
                    cnt++;
        cout << cnt << '\n';
    }
    
    return 0;
}