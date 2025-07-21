#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    // Set to store positions of pieces
    unordered_set<long long> pieces;
    
    // Directions a piece can move to capture another piece
    int dir[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    // Mark all squares that can be captured by any piece
    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        pieces.insert((x - 1) * N + y);
        
        for (auto &d : dir) {
            long long nx = x + d[0];
            long long ny = y + d[1];
            
            if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                pieces.insert((nx - 1) * N + ny);
            }
        }
    }
    
    // Total number of empty squares
    long long total_squares = N * N;
    long long empty_squares = total_squares - pieces.size();
    
    cout << empty_squares << endl;
    
    return 0;
}