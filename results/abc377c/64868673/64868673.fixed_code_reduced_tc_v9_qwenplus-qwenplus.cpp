#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int M;
    cin >> N >> M;
    
    // Set to store all positions that are either occupied or under attack
    set<pair<long long, long long>> forbidden;
    
    // Knight move patterns (dx, dy)
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Current piece position
        forbidden.insert({a, b});
        
        // Check all 8 possible attack positions
        for (const auto& [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            
            // Only consider valid positions
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }
    
    // The answer is total squares minus forbidden squares
    cout << N * N - (long long)forbidden.size() << endl;
    
    return 0;
}