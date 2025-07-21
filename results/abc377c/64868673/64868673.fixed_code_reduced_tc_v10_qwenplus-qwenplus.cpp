#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int M;
    cin >> N >> M;
    
    // Set to store all positions that are either occupied by existing pieces
    // or can be attacked by existing pieces
    unordered_set<string> forbidden;
    
    // Directions for knight moves (8 possible L-shaped moves)
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Mark current piece position
        forbidden.insert(to_string(a) + "," + to_string(b));
        
        // Mark all squares this piece can attack
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            
            // Only consider valid positions within the board
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert(to_string(x) + "," + to_string(y));
            }
        }
    }
    
    // Total number of cells: N*N
    // Subtract the number of forbidden cells
    cout << N * N - static_cast<long long>(forbidden.size()) << endl;
    
    return 0;
}