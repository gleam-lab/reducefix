#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t N;
    int M;
    cin >> N >> M;
    
    unordered_set<int64_t> attacked;
    unordered_set<int64_t> pieces;
    
    // Directions for squares that can capture a piece at (i,j)
    // These are the positions relative to (i,j) that can be used to capture
    array<pair<int64_t, int64_t>, 8> capture_directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        
        // Add this piece's position
        pieces.insert(a * N + b);
        
        // For each direction, calculate the position it can attack
        for (const auto& [dx, dy] : capture_directions) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                // Only add to attacked set if it's not already a piece
                if (!pieces.count(na * N + nb)) {
                    attacked.insert(na * N + nb);
                }
            }
        }
    }
    
    // Total number of cells is N*N
    // Subtract number of existing pieces and attacked empty cells
    cout << (N * N - M - attacked.size()) << '\n';
    
    return 0;
}