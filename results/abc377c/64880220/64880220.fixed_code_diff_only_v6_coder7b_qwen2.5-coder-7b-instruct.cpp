#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<vector<bool>> board(n + 2, vector<bool>(n + 2, false));
    vector<pair<long long, long long>> pieces(m);
    
    // Mark the positions of the pieces on the board
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        board[pieces[i].first][pieces[i].second] = true;
    }
    
    // Directions for capturing moves
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // Count the number of invalid positions due to capture rules
    long long invalid_positions = 0;
    for (const auto& piece : pieces) {
        for (const auto& dir : directions) {
            long long x = piece.first + dir.first;
            long long y = piece.second + dir.second;
            if (x > 0 && x <= n && y > 0 && y <= n && !board[x][y]) {
                invalid_positions++;
                break; // Only count once per piece
            }
        }
    }
    
    // Calculate the number of valid positions
    long long valid_positions = n * n - m - invalid_positions;
    cout << valid_positions << endl;
    
    return 0;
}