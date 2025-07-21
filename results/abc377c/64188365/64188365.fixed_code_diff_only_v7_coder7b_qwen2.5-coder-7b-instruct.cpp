#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    set<pair<long long, long long>> c;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        board[a][b] = true;
        c.emplace(a, b);
        
        // Check all possible moves
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto& move : moves) {
            int x = a + move.first, y = b + move.second;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                board[x][y] = true;
            }
        }
    }
    
    cout << n * n - c.size() << endl;
    return 0;
}