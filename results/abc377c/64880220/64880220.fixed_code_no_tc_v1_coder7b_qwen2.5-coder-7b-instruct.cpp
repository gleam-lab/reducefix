#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    
    // Directions for capturing positions
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    // Count total valid positions
    long long total_positions = n * n;
    
    // Mark all occupied positions
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        ex[p] = 1;
    }
    
    // Subtract occupied positions
    total_positions -= ex.size();
    
    // Subtract positions within capturing range
    for (auto& [pos, _] : ex) {
        for (int i = 0; i < 8; i++) {
            long long x = pos.first + dx[i];
            long long y = pos.second + dy[i];
            pair<int, int> p = make_pair(x, y);
            if (x > 0 && x <= n && y > 0 && y <= n && !ex.count(p)) {
                total_positions--;
            }
        }
    }
    
    cout << total_positions << endl;
}