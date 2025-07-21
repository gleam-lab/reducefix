#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int H, W, Y;
int A[maxn][maxn];
bool F[maxn][maxn];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W >> Y;
    
    // Initialize the grid and visited array
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
            F[i][j] = true;
        }
    
    int ans = H * W;
    queue<pair<int, int>> Q;

    // Enqueue border cells
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q.push({i, j});
            }
        }
    }

    // Process each year
    for(int y = 1; y <= Y; ++y) {
        int size = Q.size();
        while(size--) {
            auto [i, j] = Q.front(); Q.pop();
            --ans;
            for(int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                    F[ni][nj] = false;
                    Q.push({ni, nj});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}