#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t N;
    int M;
    cin >> N >> M;
    
    // Set to store all positions that are either occupied or under attack
    set<pair<int64_t, int64_t>> blocked;
    
    // Directions where a piece can attack
    array<array<int64_t, 2>, 8> attack_offsets = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        
        // Add the position itself as blocked (occupied by another piece)
        blocked.emplace(a, b);
        
        // Add all positions that this piece attacks
        for (const auto& offset : attack_offsets) {
            int64_t na = a + offset[0];
            int64_t nb = b + offset[1];
            
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                blocked.emplace(na, nb);
            }
        }
    }
    
    // Total number of cells minus the number of blocked/occupied cells
    cout << (N * N - static_cast<int64_t>(blocked.size())) << "\n";
    
    return 0;
}