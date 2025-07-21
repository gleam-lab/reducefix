#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> pieces;
    
    // Collect all pieces positions
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting to zero-based index
        pieces.insert({a, b});
        
        // Check all possible moves from the current piece
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for(auto &move : moves) {
            long long x = a + move.first, y = b + move.second;
            if(x >= 0 && x < n && y >= 0 && y < n) {
                pieces.insert({x, y});
            }
        }
    }
    
    // Total empty squares minus the occupied ones
    cout << n * n - pieces.size() << '\n';
    
    return 0;
}