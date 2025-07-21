#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int M;
    cin >> N >> M;
    
    // Set to store all positions that are either occupied by existing pieces
    // or can be attacked by them
    unordered_set<string> forbidden;
    
    // Directions where a piece can attack
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        
        // Mark the current piece position
        forbidden.insert(to_string(x) + "," + to_string(y));
        
        // Mark all squares that this piece can attack
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert(to_string(nx) + "," + to_string(ny));
            }
        }
    }
    
    // The total number of forbidden cells
    long long forbiddenCount = forbidden.size();
    
    // Total empty cells that are not forbidden
    cout << N * N - forbiddenCount << "\n";
    
    return 0;
}