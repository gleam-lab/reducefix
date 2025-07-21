#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unsafe;
    vector<long long> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<long long> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Mark the existing piece's position as unsafe
        unsafe.insert({a, b});
        
        // Mark all possible capture positions as unsafe
        for (long long j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    cout << N * N - unsafe.size() << endl;
    
    return 0;
}