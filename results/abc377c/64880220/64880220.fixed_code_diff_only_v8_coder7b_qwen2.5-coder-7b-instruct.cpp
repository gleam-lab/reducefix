#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Directions for capturing pieces
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    // Set to store all reachable positions
    set<pair<long long, long long>> reachable;
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Mark all reachable positions from the current piece
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x > 0 && x <= n && y > 0 && y <= n) {
                reachable.insert({x, y});
            }
        }
    }
    
    // Total number of empty squares
    long long total_empty_squares = n * n;
    
    // Number of reachable squares
    long long reachable_squares = reachable.size();
    
    // Output the result
    cout << total_empty_squares - reachable_squares << endl;
    
    return 0;
}