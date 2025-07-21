#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
ll ans = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool in_range(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W; }

void flood_fill(int y) {
    queue<pii> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > y) {
                q.push({i, j});
                visited[i][j] = true;
                ans++;
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (in_range(ni, nj) && !visited[ni][nj] && A[ni][nj] > y) {
                q.push({ni, nj});
                visited[ni][nj] = true;
                ans++;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int y = 1; y <= Y; ++y) {
        flood_fill(y);
        cout << ans << endl;
        ans = 0; // Reset the area for the next year
    }

    return 0;
}