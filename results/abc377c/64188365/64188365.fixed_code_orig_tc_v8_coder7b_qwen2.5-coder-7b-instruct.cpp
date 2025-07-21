#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(n));
    set<pair<long long, long long>> captures;

    // Mark positions where pieces can capture
    rep(i, m) {
        cin >> a >> b;
        --a, --b;
        rep(dx, 3) rep(dy, 3) {
            int x = a + dx - 1, y = b + dy - 1;
            if (x >= 0 && x < n && y >= 0 && y < n && (dx != 1 || dy != 1)) {
                captures.insert({x, y});
            }
        }
        board[a][b] = true;
    }

    // Count empty squares that are not in the captures set
    long long ans = 0;
    rep(i, n) rep(j, n) {
        if (!board[i][j] && captures.find({i, j}) == end(captures)) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}