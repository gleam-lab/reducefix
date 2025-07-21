#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;
    long long ans = 0;
    vector<vector<bool>> board(n + 2, vector<bool>(n + 2));

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
        board[a][b] = true;
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            if (!board[i][j]) {
                bool canPlace = true;
                vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
                for (auto& dir : directions) {
                    long long x = i + dir.first;
                    long long y = j + dir.second;
                    if (x >= 1 && x <= n && y >= 1 && y <= n && ex.find({x, y}) != ex.end()) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}