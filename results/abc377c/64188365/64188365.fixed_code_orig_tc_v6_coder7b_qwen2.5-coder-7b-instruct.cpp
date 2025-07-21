#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

bool isValid(ll x, ll y, vector<vector<bool>>& board, int n) {
    return x >= 0 && x < n && y >= 0 && y < n && !board[x][y];
}

int countSafeSquares(ll n, vector<pair<ll, ll>>& positions) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    // Mark all positions where pieces are already placed
    for(auto& pos : positions) {
        board[pos.first - 1][pos.second - 1] = true;
    }

    // Directions for the moves a piece can make
    vector<pair<ll, ll>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    // Mark all squares that can be captured by any piece
    for(auto& pos : positions) {
        for(auto& dir : directions) {
            ll nx = pos.first + dir.first;
            ll ny = pos.second + dir.second;
            if(isValid(nx, ny, board, n)) {
                board[nx - 1][ny - 1] = true;
            }
        }
    }

    // Count the number of safe squares
    int safeCount = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(!board[i][j]) {
                ++safeCount;
            }
        }
    }

    return safeCount;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> positions(m);

    rep(i, m) {
        cin >> positions[i].first >> positions[i].second;
    }

    cout << countSafeSquares(n, positions) << endl;
    return 0;
}