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
    
    // Directions for attacking (di, dj)
    const array<array<int, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        
        // Store the piece position
        pieces.insert(a * N + b);
        
        // Mark all positions that this piece can attack
        for (const auto& dir : directions) {
            int64_t ni = a + dir[0];
            int64_t nj = b + dir[1];
            
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                int64_t key = ni * N + nj;
                attacked.insert(key);
            }
        }
    }
    
    // Remove positions occupied by existing pieces from attacked set
    for (int64_t pos : pieces) {
        attacked.erase(pos);
    }
    
    // Total number of squares: N*N
    // Subtract both attacked positions and occupied pieces
    int64_t total = N * N;
    int64_t unavailable = pieces.size() + attacked.size();
    
    cout << (total - unavailable) << endl;
    
    return 0;
}