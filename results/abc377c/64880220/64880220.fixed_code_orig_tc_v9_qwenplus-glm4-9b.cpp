#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Vector of pairs to store the positions of the existing pieces
    vector<pair<long long, long long>> pieces(m);
    
    // Set to store the positions of the squares that can be captured
    set<pair<long long, long long>> capturedSquares;
    
    // Indices to track the captured squares
    int captures[2 * n + 1][2 * n + 1] = {0};
    
    // Read the positions of the existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        for (int j = 0; j < 8; ++j) {
            long long dx = 2 * (j % 2) - 1; // Moves: 2, 2, -2, -2, 1, 1, -1, -1
            long long dy = 2 * (j / 2) - 1; // Moves: 1, -1, 1, -1, 2, 2, -2, -2
            long long x = a + dx;
            long long y = b + dy;
            if (x > 0 && x <= n && y > 0 && y <= n) {
                captures[x][y]++;
                if (captures[x][y] == 1) { // First time capturing this square
                    capturedSquares.insert({x, y});
                }
            }
        }
    }
    
    // Count the number of safe squares
    long long safeSquares = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (capturedSquares.find({i, j}) == capturedSquares.end()) {
                safeSquares++;
            }
        }
    }
    
    // Output the result
    cout << safeSquares << endl;
    
    return 0;
}