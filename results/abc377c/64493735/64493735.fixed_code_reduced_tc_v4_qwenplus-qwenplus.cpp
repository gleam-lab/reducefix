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
    
    // Directions that a piece can attack
    const array<array<int, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        
        // Store the piece position
        pieces.emplace(a * 1000000000 + b);
        
        // Check all 8 attacking positions
        for (const auto& dir : directions) {
            int64_t na = a + dir[0];
            int64_t nb = b + dir[1];
            
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.emplace(na * 1000000000 + nb);
            }
        }
    }
    
    // Remove positions that are already occupied by other pieces
    for (const auto& pos : pieces) {
        if (attacked.find(pos) != attacked.end()) {
            attacked.erase(pos);
        }
    }
    
    // Total number of squares = N*N
    // Subtract number of attacked positions and existing pieces
    int64_t total_squares = N * N;
    int64_t used_positions = attacked.size() + pieces.size();
    
    cout << (total_squares - used_positions) << endl;
    
    return 0;
}