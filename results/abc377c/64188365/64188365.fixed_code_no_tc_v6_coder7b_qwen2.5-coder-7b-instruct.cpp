#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

bool isValid(ll x, ll y, vector<vector<bool>>& board) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    // Mark the positions of the existing pieces
    rep(i, m) {
        long long a, b;
        cin >> a >> b;
        --a, --b;
        board[a][b] = true;
    }

    // Directions for the captures
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    // Set to keep track of invalid positions
    set<pair<ll, ll>> invalid;

    // Check all positions for capturing
    rep(i, n) {
        rep(j, n) {
            if (board[i][j]) {
                rep(k, 8) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (isValid(ni, nj, board)) {
                        invalid.insert({ni, nj});
                    }
                }
            }
        }
    }

    // Calculate the number of valid positions
    ll validPositions = n * n - invalid.size();

    cout << validPositions << endl;
}