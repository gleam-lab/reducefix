#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions of existing pieces
    set<pair<long long, long long>> ex;
    
    // Directions for capturing pieces
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    // Read positions of existing pieces and mark them in the set
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
        
        // Check all possible capture positions
        for (int d = 0; d < 8; ++d) {
            long long x = a + dx[d];
            long long y = b + dy[d];
            if (x > 0 && x <= n && y > 0 && y <= n) {
                ex.insert({x, y});
            }
        }
    }

    // Calculate the number of empty squares
    long long total_squares = n * n;
    long long occupied_squares = ex.size();
    long long empty_squares = total_squares - occupied_squares;

    // Output the result
    cout << empty_squares << endl;
}