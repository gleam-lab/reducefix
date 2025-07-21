#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 10;
vector<vector<bool>> board(MAXN, vector<bool>(MAXN, false));
vector<vector<bool>> unsafe(MAXN, vector<bool>(MAXN, false));

void markUnsafe(int x, int y) {
    static const int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    static const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
    
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= MAXN && ny >= 1 && ny <= MAXN) {
            unsafe[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        markUnsafe(a, b);
    }

    long long safeCount = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!unsafe[i][j]) {
                ++safeCount;
            }
        }
    }

    cout << safeCount << endl;

    return 0;
}