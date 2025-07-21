#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> ex;
    long long ans = 0;
    
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p = make_pair(a - 1, b - 1); // Adjusting indices to zero-based
        if (!ex.count(p)) {
            ex.insert(p);
            ans++;
            
            vector<pair<long long, long long>> directions = {
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            };
            
            for (auto &dir : directions) {
                long long x = a + dir.first - 1, y = b + dir.second - 1; // Adjusting indices to zero-based
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    pair<long long, long long> neighbor = make_pair(x, y);
                    if (!ex.count(neighbor)) {
                        ex.insert(neighbor);
                        ans++;
                    }
                }
            }
        }
    }
    
    cout << n * n - ans << endl;
    return 0;
}