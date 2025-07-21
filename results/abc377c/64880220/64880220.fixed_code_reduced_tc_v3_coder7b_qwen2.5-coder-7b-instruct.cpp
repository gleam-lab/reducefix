#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        long long pos = (a - 1) * n + b;
        
        // Check if the position is already occupied
        if (!ex.count(pos)) {
            ex.insert(pos);
            
            // Mark all positions that can be captured from this position
            vector<pair<long long, long long>> directions = {
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            };
            
            for (const auto& [dx, dy] : directions) {
                long long x = a + dx;
                long long y = b + dy;
                
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    long long capture_pos = (x - 1) * n + y;
                    if (!ex.count(capture_pos)) {
                        ex.insert(capture_pos);
                        --ans;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}