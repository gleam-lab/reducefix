#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store all attacked squares
    set<pair<long long, long long>> attacked;
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        for (int d = 0; d < 8; ++d) {
            long long x = a + dx[d];
            long long y = b + dy[d];
            
            // Check if the new position is within bounds
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                attacked.insert({x, y});
            }
        }
    }
    
    // Total number of squares minus the number of attacked squares
    long long total_squares = n * n;
    long long result = total_squares - attacked.size();
    
    cout << result << endl;
    
    return 0;
}