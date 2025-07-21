#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<pair<long long, long long>> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p = make_pair(a - 1, b - 1); // Adjusting indices to zero-based
        
        if (!ex.count(p)) {
            ex.insert(p);
            
            for (int dir = 0; dir < 8; ++dir) {
                long long x = a + dx[dir] - 1;
                long long y = b + dy[dir] - 1;
                
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    pair<long long, long long> neighbor = make_pair(x, y);
                    if (!ex.count(neighbor)) {
                        --ans;
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}