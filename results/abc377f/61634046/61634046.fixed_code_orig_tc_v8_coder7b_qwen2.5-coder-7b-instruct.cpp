#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;

int n, m;
bool vis[MAXN][MAXN];
int row_cnt[MAXN], col_cnt[MAXN], diag1_cnt[MAXN << 1], diag2_cnt[MAXN << 1];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        vis[x][y] = true;
        ++row_cnt[x];
        ++col_cnt[y];
        ++diag1_cnt[x + y];
        ++diag2_cnt[x - y + n];
    }

    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!vis[i][j] && !row_cnt[i] && !col_cnt[j] && !diag1_cnt[i + j] && !diag2_cnt[i - j + n]) {
                ++res;
            }
        }
    }

    cout << res << endl;
    return 0;
}