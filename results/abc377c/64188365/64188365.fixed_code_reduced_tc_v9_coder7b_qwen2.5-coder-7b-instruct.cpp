#include <bits/stdc++.h>
using namespace std;

const int DIRS[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> captured;
    
    rep(i, m) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting indices to zero-based
        
        for (auto &dir : DIRS) {
            long long x = a + dir[0];
            long long y = b + dir[1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                captured.insert({x, y});
            }
        }
    }
    
    cout << n * n - captured.size() << endl;
    return 0;
}