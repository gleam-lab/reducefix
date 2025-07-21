#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<long long, long long>> unsafe;
    long long n, m;
    cin >> n >> m;
    
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        unsafe.insert({a, b});
        
        for (int j = 0; j < 8; j++) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                unsafe.insert({x, y});
            }
        }
    }
    
    cout << n * n - unsafe.size() << endl;
    return 0;
}