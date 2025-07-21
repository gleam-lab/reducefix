#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    sort(pieces.begin(), pieces.end());
    
    // Initialize the number of empty squares
    long long emptySquares = n * n;
    
    // For each piece, calculate the number of affected squares
    for (const auto& p : pieces) {
        long long a = p.first;
        long long b = p.second;
        
        // Check row and column
        if (find(pieces.begin(), pieces.end(), {a, b}) == pieces.end()) {
            emptySquares -= 2; // Subtract the two squares in the row and column
        }
        
        // Check diagonals
        long long d1 = a - b + 1;
        long long d2 = a + b - 1;
        if (find(pieces.begin(), pieces.end(), {a - d1, d1}) == pieces.end()) {
            emptySquares -= 2; // Subtract the two squares on the first diagonal
        }
        if (find(pieces.begin(), pieces.end(), {a - d2, d2}) == pieces.end()) {
            emptySquares -= 2; // Subtract the two squares on the second diagonal
        }
    }
    
    // Output the number of empty squares
    cout << emptySquares << endl;
    
    return 0;
}