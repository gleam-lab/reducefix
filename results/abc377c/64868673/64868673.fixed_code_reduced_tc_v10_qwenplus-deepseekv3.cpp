#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<long long, long long>> forbidden;
    long long n, m;
    cin >> n >> m;
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                forbidden.insert({x, y});
            }
        }
    }
    
    cout << n * n - forbidden.size() << endl;
    return 0;
}