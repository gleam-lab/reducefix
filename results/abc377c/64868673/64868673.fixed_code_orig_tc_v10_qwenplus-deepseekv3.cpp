#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }
    
    long long total_attacked = attacked.size();
    long long total_pieces = pieces.size();
    
    // Positions that are either attacked or occupied
    for (auto p : pieces) {
        if (attacked.count(p)) {
            total_attacked--;
        }
    }
    
    long long safe = N * N - total_attacked - total_pieces;
    cout << max(safe, 0LL) << endl;
    
    return 0;
}