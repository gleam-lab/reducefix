#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> c;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    rep(i, m) {
        long long a, b;
        cin >> a >> b;
        --a; --b;
        
        c.emplace(a, b);
        board[a][b] = true;
        
        // Check all possible moves and mark them as occupied
        if (a + 2 < n && b + 1 < n) {
            c.emplace(a + 2, b + 1);
            board[a + 2][b + 1] = true;
        }
        if (a + 2 < n && b - 1 >= 0) {
            c.emplace(a + 2, b - 1);
            board[a + 2][b - 1] = true;
        }
        if (a + 1 < n && b + 2 < n) {
            c.emplace(a + 1, b + 2);
            board[a + 1][b + 2] = true;
        }
        if (a + 1 < n && b - 2 >= 0) {
            c.emplace(a + 1, b - 2);
            board[a + 1][b - 2] = true;
        }
        if (a - 2 >= 0 && b + 1 < n) {
            c.emplace(a - 2, b + 1);
            board[a - 2][b + 1] = true;
        }
        if (a - 2 >= 0 && b - 1 >= 0) {
            c.emplace(a - 2, b - 1);
            board[a - 2][b - 1] = true;
        }
        if (a - 1 >= 0 && b + 2 < n) {
            c.emplace(a - 1, b + 2);
            board[a - 1][b + 2] = true;
        }
        if (a - 1 >= 0 && b - 2 >= 0) {
            c.emplace(a - 1, b - 2);
            board[a - 1][b - 2] = true;
        }
    }

    // Calculate the number of available positions
    long long ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (!board[i][j]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}