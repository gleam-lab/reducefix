#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    set<pair<long long, long long>> occupied;

    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting for 0-based indexing
        board[a][b] = true;
        occupied.insert({a, b});
    }

    long long safeCount = 0;

    for(long long i = 0; i < n; ++i) {
        for(long long j = 0; j < n; ++j) {
            if(board[i][j]) continue;
            bool safe = true;
            vector<pair<long long, long long>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for(auto& [dx, dy]: moves) {
                long long x = i + dx, y = j + dy;
                if(isValid(x, y, n) && board[x][y]) {
                    safe = false;
                    break;
                }
            }
            if(safe) ++safeCount;
        }
    }

    cout << safeCount << '\n';

    return 0;
}