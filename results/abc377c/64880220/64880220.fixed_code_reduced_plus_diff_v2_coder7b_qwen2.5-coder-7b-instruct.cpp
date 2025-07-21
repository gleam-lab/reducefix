#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions that can be captured
    set<pair<long long, long long>> capture_set;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        for (int d = 0; d < 8; ++d) {
            long long x = a + dx[d];
            long long y = b + dy[d];
            
            if (x > 0 && x <= n && y > 0 && y <= n) {
                capture_set.insert({x, y});
            }
        }
    }

    // Total number of squares minus the number of squares that can be captured
    long long valid_squares = n * n - capture_set.size();
    cout << valid_squares << endl;

    return 0;
}