#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e3 + 5;

int n, m;
int row[N], col[N], up[2][N], down[2][N];
bool vis[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        row[i] = y, col[i] = x, up[y % 2][++up[y % 2][0]] = y - x, down[(x + y) % 2][++down[(x + y) % 2][0]] = x + y;
        vis[x][y] = true;
    }

    sort(row + 1, row + m + 1);
    sort(col + 1, col + m + 1);
    sort(up[0] + 1, up[0] + up[0][0] + 1);
    sort(up[1] + 1, up[1] + up[1][0] + 1);
    sort(down[0] + 1, down[0] + down[0][0] + 1);
    sort(down[1] + 1, down[1] + down[1][0] + 1);

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!vis[i][j]) {
                bool flag = true;
                int idx = lower_bound(row + 1, row + m + 1, j) - row;
                if(idx <= m && row[idx] == j && (i + j >= down[col[idx] % 2][1] && i + j <= down[col[idx] % 2][down[col[idx] % 2][0]])) {
                    flag = false;
                }
                idx = lower_bound(col + 1, col + m + 1, i) - col;
                if(idx <= m && col[idx] == i && (i - j >= up[row[idx] % 2][1] && i - j <= up[row[idx] % 2][up[row[idx] % 2][0]])) {
                    flag = false;
                }
                idx = lower_bound(up[0] + 1, up[0] + up[0][0] + 1, j - i) - up[0];
                if(idx <= up[0][0] && up[0][idx] == j - i && (i + j >= down[1][1] && i + j <= down[1][down[1][0]])) {
                    flag = false;
                }
                idx = lower_bound(down[1] + 1, down[1] + down[1][0] + 1, i + j) - down[1];
                if(idx <= down[1][0] && down[1][idx] == i + j && (i - j >= up[0][1] && i - j <= up[0][up[0][0]])) {
                    flag = false;
                }
                if(flag) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}