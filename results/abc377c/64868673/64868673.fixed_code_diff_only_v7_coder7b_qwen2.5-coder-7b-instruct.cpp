#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store all squares that can be captured
    set<pair<long long, long long>> captured_squares;
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        for (int d = 0; d < 8; ++d) {
            long long x = a + dx[d];
            long long y = b + dy[d];
            
            // Check if the new position is within bounds
            if (x > 0 && x <= n && y > 0 && y <= n) {
                captured_squares.insert({x, y});
            }
        }
    }
    
    // Calculate the number of available squares
    long long total_squares = n * n;
    long long available_squares = total_squares - captured_squares.size();
    
    cout << available_squares << endl;
    
    return 0;
}