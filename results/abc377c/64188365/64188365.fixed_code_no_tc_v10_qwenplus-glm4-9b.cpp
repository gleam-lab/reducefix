#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    
    // Read the positions of all existing pieces
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first;
        --pieces[i].second;
    }
    
    // Sort the pieces to process them in a consistent order
    sort(pieces.begin(), pieces.end());
    
    long long safeSquares = n * n; // Initially, all squares are safe
    long long x, y;

    // Iterate over each piece to mark the unsafe squares
    for (const auto& p : pieces) {
        x = p.first;
        y = p.second;
        
        // Check the 3x3 area around the current piece
        if (x + 2 < n) {
            if (y + 1 < n) safeSquares--; // (x+2, y+1)
            if (y - 1 >= 0) safeSquares--; // (x+2, y-1)
        }
        if (x + 1 < n) {
            if (y + 2 < n) safeSquares--; // (x+1, y+2)
            if (y - 2 >= 0) safeSquares--; // (x+1, y-2)
        }
        if (x - 1 >= 0) {
            if (y + 2 < n) safeSquares--; // (x-1, y+2)
            if (y - 2 >= 0) safeSquares--; // (x-1, y-2)
        }
        if (x - 2 >= 0) {
            if (y + 1 < n) safeSquares--; // (x-2, y+1)
            if (y - 1 >= 0) safeSquares--; // (x-2, y-1)
        }
    }

    // Output the number of safe squares
    cout << safeSquares << endl;
}