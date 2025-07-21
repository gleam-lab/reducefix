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

    // Direction vectors for all 8 possible L-shaped moves
    const array<array<int, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        
        // Store the piece position
        pieces.insert(a * 1'000'000'000 + b);

        // Mark all positions that this piece can attack
        for (const auto& dir : directions) {
            int64_t na = a + dir[0];
            int64_t nb = b + dir[1];
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.insert(na * 1'000'000'000 + nb);
            }
        }
    }

    // Remove positions that are already occupied by pieces
    for (const auto& pos : pieces) {
        attacked.erase(pos);
    }

    // Total number of squares: N*N
    // Subtract the number of attacked squares and existing pieces
    cout << (int64_t)(N * N) - (int64_t)(attacked.size() + pieces.size()) << "\n";

    return 0;
}